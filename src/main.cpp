#include <Arduino.h>
#include <U8g2lib.h>
#include <Wire.h>

// Initialize the SSD1306 display via I2C for the Heltec WiFi Kit 32
// Pins for Heltec V1/V2: SDA = 4, SCL = 15, Reset = 16
U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ 16, /* clock=*/ 15, /* data=*/ 4);

// Text to scroll (Note: logisoso62_tn is a numbers-and-symbols-only ultra-large font to save RAM)
const char* scrollMessage = "_8248_";

int16_t xPosition;
int16_t textWidth;

void setup() {
  // Wake up the display wire hardware
  pinMode(16, OUTPUT);
  digitalWrite(16, LOW);
  delay(50);
  digitalWrite(16, HIGH);

  u8g2.begin();
  
  // Set a massive 62-pixel tall native font block
  u8g2.setFont(u8g2_font_logisoso62_tn); 
  u8g2.setFontMode(0); // Enable solid background masking

  // Calculate pixel length of the text string
  textWidth = u8g2.getUTF8Width(scrollMessage);
  
  xPosition = 128; // Start off the right side of the screen
}

void loop() {
  u8g2.clearBuffer();
  
  // Draw the text (Y coordinate is the baseline, so 62 places it perfectly near the bottom)
  u8g2.drawUTF8(xPosition, 62, scrollMessage);
  
  // Create a continuous seamless look
  if (xPosition < 0) {
    u8g2.drawUTF8(xPosition + textWidth, 62, scrollMessage);
  }
  
  u8g2.sendBuffer();
  
  // Scroll leftwards
  xPosition -= 2;
  if (xPosition <= -textWidth) {
    xPosition = 0;
  }
  
  delay(10);
}
