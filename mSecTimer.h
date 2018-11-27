#ifndef __MSEC_TIMER__
#define __MSEC_TIMER__
#include "Arduino.h"


class mSecTimer {

public:
		mSecTimer();
		bool trueforSeconds (bool bedingung, int msek);
		bool hasElapsedTimer (void);
		bool hasElapsedOrNotBeenStarted (void);
		bool hasElapsedAndStarted (void);
		void startTimer(int mSec);
		void stopTimer(void);
		typedef struct
		{
			unsigned long starttime_ms;
			unsigned long stoptime_ms;
			unsigned long interval;
			bool running;
		} ms_timer_t;
private:
		ms_timer_t _timer;
		bool _hasBeenStartedmSecTimer(void);
		unsigned long _msTimerGetTimeRemaining(void);


};

#endif
