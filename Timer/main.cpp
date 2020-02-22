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
	std::shared_ptr<Timer> t(new Timer());
	t->SetHeapIndex(-1);
	t->SetCallBackFunc(TimerHandler);
	t->SetInterval(1000);
	t->SetTimerType(eTimerType::CIRCLE);
	auto time_now = std::chrono::system_clock::now();
	auto duration_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch());
	t->SetExpires(duration_in_ms.count() + t->GetInterval());

	TimerManager::GetInstance().AddTimer(t);

	while (true)
	{
		TimerManager::GetInstance().DetectTimers();
		std::this_thread::sleep_for(std::chrono::milliseconds(1000));
	}

	std::cin.get();
	return 0;
}