#include <Arduino.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1
);

void drawRobot(bool blinking) {
  display.clearDisplay();

  if (!blinking) {
    // Left eye
    display.fillRoundRect(15, 12, 43, 36, 7, SSD1306_WHITE);

    // Right eye
    display.fillRoundRect(70, 12, 43, 36, 7, SSD1306_WHITE);

    // Left pupil
    display.fillRoundRect(39, 21, 13, 19, 4, SSD1306_BLACK);

    // Right pupil
    display.fillRoundRect(74, 21, 13, 19, 4, SSD1306_BLACK);

    // Eye highlights
    display.fillCircle(42, 25, 3, SSD1306_WHITE);
    display.fillCircle(77, 25, 3, SSD1306_WHITE);
  } else {
    // Closed eyes
    display.drawLine(19, 30, 54, 30, SSD1306_WHITE);
    display.drawLine(74, 30, 109, 30, SSD1306_WHITE);
  }

  // Cute little smile
  display.drawLine(57, 54, 61, 57, SSD1306_WHITE);
  display.drawLine(61, 57, 67, 57, SSD1306_WHITE);
  display.drawLine(67, 57, 71, 54, SSD1306_WHITE);

  display.display();
}

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }
}

void loop() {
  drawRobot(false); // 2.5 seconds
  delay(2500);

  drawRobot(true); // 0.18 seconds
  delay(180);
}
