#pragma  once

#include <vector>
#include <stdint.h>
#include "Singleton.h"


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
	void DetectTimers();

public:
	void AddTimer(std::shared_ptr<Timer> timer);
	void RemoveTimer(std::shared_ptr<Timer> timer);

	void UpHeap(uint32_t index);
	void DownHeap(uint32_t index);
	void SwapHeap(uint32_t, uint32_t index2);

private:

	std::vector<stHeapEntry> heap_;
};
