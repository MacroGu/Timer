#include "TimerManager.h"
#include "Timer.h"




void TimerManager::AddTimer(std::shared_ptr<Timer> timer)
{
	if (!timer)
	{
		return;
	}

	timer->SetHeapIndex(heap_.size());
	stHeapEntry entry(timer->GetExpires(), timer);
	heap_.push_back(entry);
	UpHeap(heap_.size() - 1);
}

void TimerManager::RemoveTimer(std::shared_ptr<Timer> timer)
{
	uint32_t index = timer->GetHeapIndex();
	if (!heap_.empty() && index < heap_.size()) 
	{
		if (index == heap_.size() - 1) 
		{
			heap_.pop_back();
		}
		else 
		{
			SwapHeap(index, heap_.size() - 1);
			heap_.pop_back();
			uint32_t parent = (index - 1) / 2;
			if (index > 0 && heap_[index].time < heap_[parent].time)
			{
				UpHeap(index);
			}
			else
			{
				DownHeap(index);
			}
		}
	}
}

void TimerManager::DetectTimers()
{
	auto time_now = std::chrono::system_clock::now();
	auto duration_in_ms = std::chrono::duration_cast<std::chrono::milliseconds>(time_now.time_since_epoch());

	while (!heap_.empty() && heap_[0].time <= duration_in_ms.count())
	{
		std::shared_ptr<Timer> timer = heap_[0].timer;
		RemoveTimer(timer);

		if (timer->GetTimerType() == CIRCLE)
		{
			timer->SetExpires(duration_in_ms.count() + timer->GetInterval());
			AddTimer(timer);
		}
		else
		{
			timer->SetHeapIndex(-1);
		}

		timer->OnTimer(duration_in_ms.count());
	}
}

void TimerManager::UpHeap(uint32_t index)
{
	uint32_t parent = (index - 1) / 2;
	while (index > 0 && heap_[index].time < heap_[parent].time)
	{
		SwapHeap(index, parent);
		index = parent;
		parent = (index - 1) / 2;
	}
}

void TimerManager::DownHeap(uint32_t index)
{
	uint32_t child = index * 2 + 1;
	while (child < heap_.size()) {
		uint32_t minChild = (child + 1 == heap_.size() || heap_[child].time < heap_[child + 1].time)
			? child
			: child + 1;
		if (heap_[index].time < heap_[minChild].time)
			break;
		SwapHeap(index, minChild);
		index = minChild;
		child = index * 2 + 1;
	}
}

void TimerManager::SwapHeap(uint32_t index1, uint32_t index2)
{
	stHeapEntry tmp = heap_[index1];
	heap_[index1] = heap_[index2];
	heap_[index2] = tmp;
	heap_[index1].timer->SetHeapIndex(index1);
	heap_[index2].timer->SetHeapIndex(index2);
}


