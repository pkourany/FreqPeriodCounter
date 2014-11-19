/*
* Test.ino for Spark Core
* 
* This test program uses the Spark PWM to generate a fixed
* frequency (500Hz) and fixed duty cycle (50%) waveform to
* be measured by the frequency counter library.
*
*/

#include "FreqPeriodCounter.h"


/* Note: connect pin D3 to pin A1 */
const int counterPin = D3;		// connect pin 3 to pin 9
const int PWMpin = A1;			// PWM only pin 9 or 10

FreqPeriodCounter counter(counterPin, micros, 0);


void setup(void) 
{
	Serial.begin(115200);

	pinMode(counterPin, INPUT);
	pinMode(PWMpin, OUTPUT);
	analogWrite(PWMpin, 128);	//Spark PWM is fixed to 500Hz.  Setup for 50% duty cycle
	attachInterrupt(counterPin, counterISR, CHANGE);
}

void loop(void) 
{
	if(!counter.ready())
		Serial.println("\nwaiting");
	else {
		Serial.print(counter.level);
		Serial.print(", ");
		Serial.print(counter.period);
		Serial.print(", ");
		Serial.print(counter.pulseWidth);
		Serial.print(", ");
		Serial.print(counter.pulseWidthLow);
		Serial.print(", ");
		Serial.println(counter.hertz());
	}

}


void counterISR()
{
	counter.poll();
}

