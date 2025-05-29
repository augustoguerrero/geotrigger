#include <SPI.h>
#include <RF24.h>

RF24 radio(7, 8);
const byte address[6] = "00001";
const int piezoPin = A0;
const int threshold = 500;

void setup() {
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
}

void loop() {
  int piezoValue = analogRead(piezoPin);
  if (piezoValue > threshold) {
    char msg = 't';
    radio.write(&msg, sizeof(msg));
    delay(100);
  }
}