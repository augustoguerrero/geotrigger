#include <SPI.h>
#include <RF24.h>
#include <Keyboard.h>

RF24 radio(7, 8);
const byte address[6] = "00001";

void setup() {
  radio.begin();
  radio.openReadingPipe(0, address);
  radio.setPALevel(RF24_PA_MIN);
  radio.startListening();
  Keyboard.begin();
}

void loop() {
  if (radio.available()) {
    char msg;
    radio.read(&msg, sizeof(msg));
    if (msg == 't') {
      Keyboard.write('t');
    }
  }
}