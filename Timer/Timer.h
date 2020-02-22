// 定时器的实现， 仅 支持单线程

#pragma once

#include <functional>
#include <chrono>
#include <vector>
#include <stdint.h>
#include "Singleton.h"

// 定时器类型
enum class eTimerType : uint8_t {
	ONCE,			// 仅执行一次
	CIRCLE			// 循环执行
};

class Timer {
public:

	Timer();
	~Timer();

	void Stop();

	void SetHeapIndex(const uint32_t& index) { heap_index = index; }
	uint32_t GetHeapIndex() { return heap_index; }
	void SetExpires(const uint64_t& _expires) { expire_time = _expires; }
	uint64_t GetExpires() { return expire_time; }
	void SetInterval(const uint32_t& _interval) { interval = _interval; }
	uint32_t GetInterval() { return interval; }
	void SetTimerType(const eTimerType& _timer_type) { timer_type = _timer_type; }
	eTimerType GetTimerType() { return timer_type; }
	// 设置回调函数
	void SetCallBackFunc(const std::function<void(uint32_t)>& call_back);
	// 时间达到回调   elapse：距离上次回调间隔
	void OnTimer(uint32_t elapse);

private:
	eTimerType timer_type;		//定时器类型
	uint32_t interval;			//定时器回调间隔 
	uint64_t expire_time;		//定时器失效时间
	uint32_t heap_index;		//在堆中的index
	std::function<void(uint32_t)> timer_call_back;		// 回调函数

};

