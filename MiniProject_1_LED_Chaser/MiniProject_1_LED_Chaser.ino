/*
 * Jingkun Li | MiniProject_1 | Advisor: Prof. Carlotta Berry, Ph.D.
 * Project: 8-Channel Sequential LED Chaser
 * Board: Arduino Uno
 * Description: Sequentially illuminates an 8-LED array from left to right using active-low sink logic.
 */

int led_array[8] = {2, 3, 4, 5, 6, 7, 8, 9};
int flash_speed = 100;  // the gap of flashing (ms)

// light up the led from the left to right
void led_flash(void)
{
  for(int i = 0; i < 8; i++)
  {
    // turn off all the led
    for(int j = 0; j < 8; j++) digitalWrite(led_array[j], HIGH);
    // light up the current led
    digitalWrite(led_array[i], LOW);
    delay(flash_speed);
  }
}

// turn all the leds off
void led_turn_off(void)
{
  for(int i = 0; i < 8; i++)
    digitalWrite(led_array[i], HIGH);
}

void setup() {
  Serial.begin(115200);
  for(int i = 0; i < 8; i++) {
    pinMode(led_array[i], OUTPUT);
    digitalWrite(led_array[i], HIGH); // turn off at first
  }
}

void loop() {
  Serial.println("start flash led!");
  led_flash();
  led_turn_off();
  delay(500); // in case the flashing is too fast
}
