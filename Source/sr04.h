/********************************************************************
  This is a library for Ultrasonic SR04.

  ------> http://www.easymcu.ir
  
  Check out the links above for our tutorials and wiring diagrams
  
  Written by Morteza Zandi for EasyMCU.
  BSD license, All text above must be included in any redistribution
 ********************************************************************/
 
	#ifndef __SR04_H__
	#define __SR04_H__ 
	
	#include "common_func.h"
	
	class SR04
	{
		public:			
		SR04(PORT_PIN_ARRAY trig_pin = P39, PORT_PIN_ARRAY echo_pin = P40);	
		void setTrig(PORT_PIN_ARRAY Pnum);
		void setEcho(PORT_PIN_ARRAY Pnum);
		float distance(void);
		
		private:
			void trig(void);
			uint8_t echo(void);	
			PORT_PIN_ARRAY Trig;
			PORT_PIN_ARRAY Echo;
	};
	
	#endif
	
