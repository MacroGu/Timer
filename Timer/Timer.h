// ��ʱ����ʵ�֣� �� ֧�ֵ��߳�

#pragma once

#include <functional>
#include <chrono>
#include <vector>
#include <stdint.h>
#include "Singleton.h"

// ��ʱ������
enum class eTimerType : uint8_t {
	ONCE,			// ��ִ��һ��
	CIRCLE			// ѭ��ִ��
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
	// ���ûص�����
	void SetCallBackFunc(const std::function<void(uint32_t)>& call_back);
	// ʱ��ﵽ�ص�   elapse�������ϴλص����
	void OnTimer(uint32_t elapse);

private:
	eTimerType timer_type;		//��ʱ������
	uint32_t interval;			//��ʱ���ص���� 
	uint64_t expire_time;		//��ʱ��ʧЧʱ��
	uint32_t heap_index;		//�ڶ��е�index
	std::function<void(uint32_t)> timer_call_back;		// �ص�����

};

