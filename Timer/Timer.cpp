#define _CRT_SECURE_NO_WARNINGS
#include "Timer.h"
#ifdef _MSC_VER
# include <sys/timeb.h>
#else
# include <sys/time.h>
#endif




Timer::Timer() : heapIndex_(-1)
{
}

Timer::~Timer()
{
	Stop();
}

void Timer::Stop()
{
	if (heapIndex_ != -1) 
	{
		heapIndex_ = -1;
	}
}

void Timer::OnTimer(uint64_t now)
{

	timerFun_();

}

