// 定时器的实现， 仅 支持单线程

#pragma once

#include <functional>
#include <chrono>
#include <vector>
#include <stdint.h>
#include "Singleton.h"
#include "Definition.h"


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
	void SetTimerID(const uint32_t& _id) { id = _id; }
	uint32_t GetTimerID() { return id; }
	// 设置回调函数
	void SetCallBackFunc(const std::function<void(uint64_t)>& call_back);
	// 时间达到回调   elapse：距离上次回调间隔
	void OnTimer(uint64_t elapse);

private:
	eTimerType timer_type;		//定时器类型
	uint32_t interval;			//定时器回调间隔 
	uint64_t expire_time;		//定时器失效时间
	uint32_t heap_index;		//在堆中的index
	std::function<void(uint64_t)> timer_call_back;		// 回调函数
	uint32_t id;				// 唯一ID

};

