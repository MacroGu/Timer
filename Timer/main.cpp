#include <iostream>
#include <thread>
#include <chrono>
#include "Timer.h"
#include "TimerManager.h"

void TimerHandler()
{
	std::cout << "TimerHandler" << std::endl;
}

int main()
{
	std::shared_ptr<Timer> t(new Timer());
	t->Start(&TimerHandler, 1000);
	TimerManager::GetInstance().AddTimer(t);

	while (true)
	{
		TimerManager::GetInstance().DetectTimers();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}

	std::cin.get();
	return 0;
}