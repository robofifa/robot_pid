/* .
*/
#include "Encoder.h"
#include "PID.h"
#include "MX1508.h"


// the numbers of the motor pins
const int M1A = 26;  // 26 corresponds to GPIO26
const int M1B = 18;  // ""

// setting PWM properties
const int freq = 5000; // range at least 100-5000 Hz
const int ledChannel1 = 0; // 16 channels: 0-15, but every even channels shares its freq with the one before, thus 0&1, 2&3...
const int ledChannel2 = 2; // 16 channels: 0-15, but every even channels shares its freq with the one before, thus 0&1, 2&3...
const int resolution = 8; // 1-16 bits
const int max_power = 100;
const int min_power = -100;


Encoder *Left;

const uint8_t CHAN_A = 16;
const uint8_t CHAN_B = 17;
const unsigned int FILTERLENGTH = 1023;


MX1508 M1(M1A, M1B, freq, ledChannel2, resolution);

void setup() {
  Serial.begin(115200);
  /* Initialize PCNT event queue and PCNT functions */
  M1.init();
  Left = new Encoder(PCNT_UNIT_0, CHAN_A, CHAN_B, Encoding::X4, FILTERLENGTH);
}

unsigned long count = 0;

void loop() {
  /* Wait for the event information passed from PCNT's interrupt handler.
   * Once received, decode the event type and print it on the serial monitor.
   */
  if(count < (millis() - 100)){
    count = millis();
    Serial.println(Left->ReadAndReset());
    M1.setDutyCycle(0);
  }

}
