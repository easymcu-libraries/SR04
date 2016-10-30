/********************************************************************
  This is a library for Ultrasonic SR04.

  ------> http://www.easymcu.ir

  Check out the links above for our tutorials and wiring diagrams

  Written by Morteza Zandi for EasyMCU.
  BSD license, All text above must be included in any redistribution
********************************************************************/

#include "sr04.h"

SR04::SR04(PORT_PIN_ARRAY trig_pin, PORT_PIN_ARRAY echo_pin)
{
	setTrig(trig_pin);
	setEcho(echo_pin);
}

void SR04::setTrig(PORT_PIN_ARRAY Pnum)
{
	Trig = Pnum;
	io.mode(Trig, OUTPUT);
}

void SR04::setEcho(PORT_PIN_ARRAY Pnum)
{
	Echo = Pnum;
	io.mode(Echo, INPUT_PULLDOWN);
}	

void SR04::trig(void)
{
	io.set(Trig);
	delay.us(20);
	io.reset(Trig);	
}

uint8_t SR04::echo(void)
{
	return (uint8_t)(io.read(Echo));
}		

float SR04::distance(void)
{
		uint32_t start_time, delT, timeoutCounter;

		trig();

		start_time = timer.millis();

		while(echo() == 0)
		{
			if(deltaTmillis(start_time) > 150)
				break;
		}

		start_time = timer.micros();

		while(echo() != 0)
		{
			if(deltaTmicros(start_time) > 150000)
				break;				
		}

		delT = timer.deltaTmicros(start_time);

		return (float)(((float)delT*343.2*100.0)/(2.0*1000000.0));		
}

