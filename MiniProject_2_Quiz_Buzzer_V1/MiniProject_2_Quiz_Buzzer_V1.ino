/*
 * Jingkun Li | MiniProject_2 | Advisor: Prof. Carlotta Berry, Ph.D.
 * Project: Quiz Buzzer System V1 (Electronic Timing & Debounce)
 * Board: Arduino Uno
 * Hardware: LED, Push Button, 4-digit 7-segment display (TM1637), Buzzer
 * Description: This program implements a quiz buzzer. When the button is pressed,
 * the LED turns on, the buzzer sounds, and the time interval since the previous press
 * is displayed on the 4-digit display (in seconds).
 * It can be used to measure response times in a quiz competition.
 */

#include <TM1637Display.h>  // install TM1637Display

// define CLK and DIO of the Display
#define CLK A5
#define DIO A4
TM1637Display display(CLK, DIO);  // set the board to be displayed

int led_out = 11;    // LED pin 11
int button_pin = 7;  // button pin 7
int buzzer = 9;      // buzzer pin 9

int value;
unsigned long lastPressTime = 0;  // the last time of pressing
unsigned long interval = 0;       // the gap of two pressing time (in seconds)

// move debounce variables to global scope
unsigned long lastDebounceTime = 0;
int lastButtonState = HIGH;  // the last condition of the button
int stableState = HIGH;      // the static condition

void setup() {
  // put your setup code here, to run once:
  pinMode(led_out, OUTPUT);           // initialize the LED pin output
  pinMode(button_pin, INPUT_PULLUP);  // initialize the button input with internal pull-up
  digitalWrite(led_out, LOW);         // turn the LED off at first
  pinMode(buzzer, OUTPUT);            // initialize the buzzer pin output
  digitalWrite(buzzer, LOW);          // ensure buzzer is off at startup
  display.setBrightness(0x0f);        // set the brightness of 0x0f
  display.showNumberDec(0);           // display 0 at first
}

void loop() {
  value = digitalRead(button_pin);  // read the condition of the button

  // move to top to capture presses regardless of LED or buzzer state
  int reading = digitalRead(button_pin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();  // if the condition changes, reset
  }

  if ((millis() - lastDebounceTime) > 50) {  // set the bounce time
    if (reading != stableState) {
      stableState = reading;
      // if the static condition is low, it means we press the button
      if (stableState == LOW) {
        unsigned long now = millis();
        interval = (now - lastPressTime) / 1000;  // divided 1000 to get the time interval in second
        lastPressTime = now;                      // update the time of last pressing
        // the maximum of interval should be 9999 (seconds)
        if (interval > 9999) interval = 9999;
        display.showNumberDec(interval);          // display in seconds
      }
    }
  }
  lastButtonState = reading;  // save in order to compare for the next time

  if (stableState == LOW)  // if the button is pressed (connected to GND)
  {
    digitalWrite(led_out, LOW);   // turn on the LED immediately
    digitalWrite(buzzer, HIGH);   // make continuous sound
  } else  // button is released
  {
    digitalWrite(led_out, HIGH);  // turn off the LED
    digitalWrite(buzzer, LOW);    // stop the sound immediately
  }
}
