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

    // Pupils looking towards each other
    display.fillRoundRect(39, 21, 13, 19, 4, SSD1306_BLACK);
    display.fillRoundRect(74, 21, 13, 19, 4, SSD1306_BLACK);

    // Eye highlights
    display.fillCircle(42, 25, 2, SSD1306_WHITE);
    display.fillCircle(77, 25, 2, SSD1306_WHITE);
  } else {
    // Closed eyes
    display.drawLine(19, 30, 54, 30, SSD1306_WHITE);
    display.drawLine(74, 30, 109, 30, SSD1306_WHITE);
  }

  // Little smile
  display.drawLine(57, 54, 61, 57, SSD1306_WHITE);
  display.drawLine(61, 57, 67, 57, SSD1306_WHITE);
  display.drawLine(67, 57, 71, 54, SSD1306_WHITE);

  display.display();
}

void drawThickLine(int x1, int y1, int x2, int y2)
{
  for (int i = -2; i <= 2; i++) {
    display.drawLine(x1, y1 + i, x2, y2 + i, SSD1306_WHITE);
  }
}

void drawHappy() {
  display.clearDisplay();

  // Left happy eye
  drawThickLine(27, 30, 33, 21);
  drawThickLine(33, 21, 41, 18);
  drawThickLine(41, 18, 49, 21);
  drawThickLine(49, 21, 55, 30);

  // Right happy eye
  drawThickLine(73, 30, 79, 21);
  drawThickLine(79, 21, 87, 18);
  drawThickLine(87, 18, 95, 21);
  drawThickLine(95, 21, 101, 30);

  // Left blush or heart
  display.fillCircle(19, 40, 2, SSD1306_WHITE);
  display.fillCircle(24, 42, 2, SSD1306_WHITE);
  display.fillCircle(29, 40, 2, SSD1306_WHITE);
  display.fillCircle(24, 45, 1, SSD1306_WHITE);

  // Right blush or heart
  display.fillCircle(99, 40, 2, SSD1306_WHITE);
  display.fillCircle(104, 42, 2, SSD1306_WHITE);
  display.fillCircle(109, 40, 2, SSD1306_WHITE);
  display.fillCircle(104, 45, 1, SSD1306_WHITE);

  // Happy half-circle mouth
  int centerX = 64;
  int centerY = 44;
  int radius = 15;

  for (int y = 0; y <= radius; y++) {
    int halfWidth = sqrt(radius * radius - y * y);

    display.drawFastHLine(
      centerX - halfWidth,
      centerY + y,
      2 * halfWidth + 1,
      SSD1306_WHITE
    );
  }

  display.display();
}
void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true);
  }
}
void loop() {
  drawHappy();
  delay(2500);
 
}
