#include <iostream>
#include <thread>
#include <chrono>
#include "Timer.h"
#include "TimerManager.h"

void TimerHandler(uint32_t elapse)
{
	std::cout << "TimerHandler: " << elapse << std::endl;
}

int main()
{
	// 添加逻辑处理定时器
	TimerManager::GetInstance().ScheduleTimer(0, TIME_LENGTH_PER_FRAME, eTimerType::CIRCLE, TimerHandler);
	TimerManager::GetInstance().ScheduleTimer(0, TIME_LENGTH_PER_SECONDS, eTimerType::CIRCLE, TimerHandler);
	TimerManager::GetInstance().ScheduleTimer(0, TIME_LENGTH_PER_MINUTE, eTimerType::CIRCLE, TimerHandler);
	TimerManager::GetInstance().ScheduleTimer(0, TIME_LENGTH_PER_HOUR, eTimerType::CIRCLE, TimerHandler);

	while (true)
	{
		TimerManager::GetInstance().DetectTimers();
		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	std::cin.get();
	return 0;
}