#pragma  once

#include <vector>
#include <functional>
#include <stdint.h>
#include "Singleton.h"
#include "Definition.h"

class Timer;

struct stHeapEntry 
{
	uint64_t time;
	std::shared_ptr<Timer> timer;

	stHeapEntry(const uint64_t& _time, std::shared_ptr<Timer> _timer)
	{
		time = _time;
		timer = _timer;
	}

};


class TimerManager : public ISingleton<TimerManager>
{
public:
	// 调用及分配timer
	void DetectTimers();
	// 部署一个 timer
	uint32_t ScheduleTimer(const uint32_t& delay, const uint32_t& interval, const eTimerType& timer_type, const std::function<void(uint64_t)>& call_back);


private:
	void AddTimer(std::shared_ptr<Timer> timer);
	void RemoveTimer(std::shared_ptr<Timer> timer);

	void UpHeap(uint32_t index);
	void DownHeap(uint32_t index);
	void SwapHeap(uint32_t, uint32_t index2);

private:

	std::vector<stHeapEntry> heap_;
};
