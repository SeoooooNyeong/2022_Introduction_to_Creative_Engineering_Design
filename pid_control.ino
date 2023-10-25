#include <Servo.h>

// Arduino pin assignment
#define PIN_LED 9
#define PIN_SERVO 10
#define PIN_IR A0
#define PIN_VAR A3

// Event interval parameters
#define _INTERVAL_DIST    20 // distance sensor interval (unit: ms)
#define _INTERVAL_SERVO   20 // servo interval (unit: ms)
#define _INTERVAL_SERIAL  20 // serial interval (unit: ms)

// EMA filter configuration for the IR distance sensor
#define _EMA_ALPHA 0      // EMA weight (range: 0 to 1)
                          // Setting _EMA_ALPHA to 0 effectively disables EMA filter.

// Servo adjustment
#define _DUTY_MAX 2500  // Servo angle: D degree
#define _DUTY_NEU 1100  // Servo angle: 0 degree
#define _DUTY_MIN 500   // Servo angle: E degree
#define _SERVO_ANGLE_DIFF 90 // Replace with |D - E| degree
#define _SERVO_SPEED 1000 // servo speed limit (unit: degree/second)

// PID Constants
#define KP 0.5
#define KI 0.1
#define KD 0.2

// global variables
float dist_filtered, dist_ema, dist_target; // unit: mm

Servo myservo;

int duty_target;    // Target duty
int duty_curr;      // Current duty

unsigned long last_sampling_time_dist;   // unit: msec
unsigned long last_sampling_time_servo;  // unit: msec
unsigned long last_sampling_time_serial; // unit: msec

bool event_dist, event_servo, event_serial; // event triggered?

// PID Variables
float previous_error = 0;
float integral = 0;

void setup() {
  // initialize GPIO pins
  pinMode(PIN_LED, OUTPUT);
  myservo.attach(PIN_SERVO);
  duty_target = duty_curr = _DUTY_NEU;

  // initialize serial port
  Serial.begin(1000000);

  // Set a target distance
  dist_target = 155; // 15.5 cm, the center of the rail
}

void loop() {
  unsigned long time_curr = millis();

  // wait until next event time
  if (time_curr >= (last_sampling_time_dist + _INTERVAL_DIST)) {
    last_sampling_time_dist += _INTERVAL_DIST;
    event_dist = true;
  }
  if (time_curr >= (last_sampling_time_servo + _INTERVAL_SERVO)) {
    last_sampling_time_servo += _INTERVAL_SERVO;
    event_servo = true;
  }
  if (time_curr >= (last_sampling_time_serial + _INTERVAL_SERIAL)) {
    last_sampling_time_serial += _INTERVAL_SERIAL;
    event_serial = true;
  }

  if (event_dist) {
    event_dist = false;

    // get a distance reading from the distance sensor
    dist_filtered = volt_to_distance(ir_sensor_filtered(10, 0.5)); // Replace n with your desired value
    dist_ema = _EMA_ALPHA * dist_ema + (1.0 - _EMA_ALPHA) * dist_filtered;

    // Calculate the error (how far the current distance is from the target)
    float error = dist_target - dist_ema;

    // Calculate the control output (duty_target) using PID control
    float P = KP * error;
    integral += error * _INTERVAL_DIST / 1000.0; // Discretize integral
    float I = KI * integral;
    float derivative = (error - previous_error) / (_INTERVAL_DIST / 1000.0);
    float D = KD * derivative;
    duty_target = _DUTY_NEU + P + I + D;

    // Update the previous error for the next iteration
    previous_error = error;
  }

  if (event_servo) {
    event_servo = false;

    // Clip the duty_target to the valid servo duty range
    if (duty_target > _DUTY_MAX) {
      duty_target = _DUTY_MAX;
    } else if (duty_target < _DUTY_MIN) {
      duty_target = _DUTY_MIN;
    }

    // Update servo position
    myservo.writeMicroseconds(duty_target);
  }

  if (event_serial) {
    event_serial = false;
    // Output the read value to the serial port
    Serial.print("Min:0,TARGET:");
    Serial.print(dist_target);
    Serial.print(",DIST:");
    Serial.println(dist_ema);
  }
}

float volt_to_distance(int a_value) {
  // Replace the below line with the equation obtained from nonlinear regression analysis
  return (6762.0 / (a_value - 9) - 4.0) * 10.0;
}

unsigned int ir_sensor_filtered(unsigned int n, float position) {
  // Eliminate spiky noise of an IR distance sensor by repeating measurement and taking a middle value
  // n: number of measurement repetition
  // position: the percentile of the sample to be taken (0.0 <= position <= 1.0)

  // The output of Sharp infrared sensor includes lots of spiky noise.
  // To eliminate such a spike, ir_sensor_filtered() performs the following two steps:
  // Step 1. Repeat measurement n times and collect n * position smallest samples, where 0 <= postion <= 1.
  // Step 2. Return the largest sample among the collected ones.

  unsigned int *ir_val, tmp, ret_idx, ret_val;
  unsigned int start_time;

  ret_idx = (unsigned int)ceil(n * position);

  // Step 1. Repeat measurement n times and collect n * position smallest samples.
  // Note: simple implementation requires an array of n elements
