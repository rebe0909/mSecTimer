#include arduino.h
#include <mSecTimer.h>

mSecTimer ms_timer; //Declare Timer

void setup() {
  // put your setup code here, to run once:
  ms_timer.startTimer(2500); //start one Timer
}

void loop() {
  // put your main code here, to run repeatedly:
	bool timerElapsed = ms_timer.hasElapsedTimer();
	if(timerElapsed)
	{
		//Do_something....
		ms_timer.startTimer(1000); //Start Timer again....
	}
}
