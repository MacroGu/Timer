#include "Timer.h"



Timer::Timer()
{
	heap_index = -1;
	interval = 0;
	expire_time = 0;
	timer_type = eTimerType::ONCE;
}

Timer::~Timer()
{
	Stop();
}

void Timer::Stop()
{
	if (heap_index != -1) 
	{
		heap_index = -1;
	}
}

void Timer::SetCallBackFunc(const std::function<void(uint32_t)>& call_back)
{
	timer_call_back = call_back;
}

void Timer::OnTimer(uint32_t elapse)
{

	timer_call_back(elapse);

}

