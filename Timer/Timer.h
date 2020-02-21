// 定时器的实现， 仅 支持单线程

#pragma once

#include <functional>
#include <chrono>
#include <vector>
#include <stdint.h>
#include "Singleton.h"

enum TimerType {
	ONCE,
	CIRCLE
};

class Timer {
public:

	Timer();
	~Timer();

	template <typename Fun>
	void Start(Fun fun, unsigned interval, TimerType timeType = CIRCLE);
	void Stop();

	void SetHeapIndex(const uint32_t& index) { heapIndex_ = index; }
	uint32_t GetHeapIndex() { return heapIndex_; }
	void SetExpires(const uint64_t& _expires) { expires_ = _expires; }
	uint64_t GetExpires() { return expires_; }
	uint32_t GetInterval() { return interval_; }
	TimerType GetTimerType() { return timerType_; }

	void OnTimer(uint64_t now);

private:
	TimerType timerType_;
	std::function<void(void)> timerFun_;
	uint32_t interval_;
	uint64_t expires_;
	uint32_t heapIndex_;
};



template <typename Fun>
inline void Timer::Start(Fun fun, uint32_t interval, TimerType timeType)
{
	Stop();
	interval_ = interval;
	timerFun_ = fun;
	timerType_ = timeType;

	auto time_now = std::chrono::system_clock::now();
	auto duration_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch());
	this->expires_ = this->interval_ + duration_in_ms.count();
}
