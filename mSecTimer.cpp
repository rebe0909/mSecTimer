/*
	mSecTimer.cpp
*/
#include "Arduino.h"
#include "mSecTimer.h"

mSecTimer::mSecTimer()
{
	_timer.starttime_ms = 0;
	_timer.stoptime_ms = 0;
	_timer.interval = 0;
	_timer.running = false;
}
void mSecTimer::stopTimer(void)
{
	_timer.running = false;
}

bool mSecTimer::hasElapsedTimer (void)
{
	return _msTimerGetTimeRemaining() == 0;
}

bool mSecTimer::hasElapsedAndStarted (void)
{
	return _msTimerGetTimeRemaining() == 0 && _hasBeenStartedmSecTimer ();
}

bool mSecTimer::hasElapsedOrNotBeenStarted (void)
{
	return _msTimerGetTimeRemaining() == 0 || !_hasBeenStartedmSecTimer();
}

void mSecTimer::startTimer(int mSec)
{
	_timer.starttime_ms = millis();
	_timer.stoptime_ms = _timer.starttime_ms + mSec;
	_timer.interval = mSec;
	_timer.running = true;
}

bool mSecTimer::_hasBeenStartedmSecTimer (void)
{
	return _timer.interval != 0;
}

unsigned long mSecTimer::_msTimerGetTimeRemaining(void)
{
	if (!_timer.running) return 0;

	unsigned long _current = millis();
	if(_timer.interval == 0 || (_current - _timer.starttime_ms) > _timer.interval )
	{
		_timer.running = false;
		return 0;
	}
	else
	{
		return _current - _timer.stoptime_ms;
	}
}
