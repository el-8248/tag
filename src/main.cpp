#include <Arduino.h>
#include "heltec.h"
#include "oled/OLEDDisplayFonts.h"

int counter = 0;

void setup() {
  // Initialize the Heltec board (Display Enable, LoRa Disable, Serial Enable, PABOOST Disable, Band)
  Heltec.begin(true, false, true, false, 915E6);

  // Set up the display font and alignment
  Heltec.display->setFont(ArialMT_Plain_16);
  Heltec.display->setTextAlignment(TEXT_ALIGN_LEFT);
}

void loop() {
  // Clear the screen buffer
  Heltec.display->clear();

  // Draw static text
  Heltec.display->drawString(0, 0, "Heltec WB32 Test");
  
  // Draw the variable counter
  String counterString = "Count: " + String(counter);
  Heltec.display->drawString(0, 24, counterString);

  // Send the buffer to the physical screen
  Heltec.display->display();

  counter++;
  delay(1000);

  Heltec.display->clear();


  Heltec.display->drawString(0, 0, "Elliott Weston Ball");
  
  Heltec.display->drawString(0, 24, "ChainLynx 8248");

  // Send the buffer to the physical screen
  Heltec.display->display();

  counter++;
  delay(1000);
  counter++;
  delay(1000);
  counter++;
  delay(1000);
  counter++;
  delay(1000);
}
