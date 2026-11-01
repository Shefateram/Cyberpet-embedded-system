#include <Arduino.h> 
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void drawPet(bool blinking) {
  display.clearDisplay();

  // Head
  display.drawRoundRect(25, 8, 78, 52, 12, SSD1306_WHITE);

  // Ears
  display.fillTriangle(34, 14, 40, 2, 49, 14, SSD1306_WHITE); // Left ear
  display.fillTriangle(79, 14, 88, 2, 95, 14, SSD1306_WHITE); // Right ear

  if (blinking) {
    // Closed eyes
    display.drawLine(39, 31, 55, 31, SSD1306_WHITE); // Left eye
    display.drawLine(73, 31, 89, 31, SSD1306_WHITE); // Right eye
  } else {
    // Open eyes
    display.fillCircle(47, 31, 7, SSD1306_WHITE); // Left eye
    display.fillCircle(81, 31, 7, SSD1306_WHITE); // Right eye
  }

  // Mouth
  display.drawLine(59, 43, 67, 43, SSD1306_WHITE); // Mouth

  display.display();
}

void setup() {
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Initialize with the I2C addr 0x3C
{
    while(true);
      }
    }
  }

void loop() {
  drawPet(false); // Draw pet with open eyes
  delay(2500);    // Wait for 2.5 seconds

  drawPet(true);  // Draw pet with closed eyes (blinking)
  delay(180);     // Wait for 0.18 seconds

  drawPet(false); // Draw pet with open eyes again
  delay(2500);    // Wait for 2.5 seconds

}
