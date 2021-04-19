#include <iostream>
#include <cppcoro/generator.hpp>
#include <cppcoro/task.hpp>
#include <cppcoro/async_manual_reset_event.hpp>
#include <cppcoro/sync_wait.hpp>
#include <cppcoro/static_thread_pool.hpp>
#include <cppcoro/when_all.hpp>
#include <future>
#include <vector>

// This is a coroutine that each time it's called will return the next number
cppcoro::generator<int> GetNextNum()
{
	int num = 0;
	while (true)
	{
		co_yield num++;
	}
}

// This is an event that can be waited on by multiple coroutines
cppcoro::async_manual_reset_event event;

cppcoro::task<> task1()
{
	// Wait until the event is set
	co_await event;
	std::cout << "task1 executing!\n";
	co_return;
}

cppcoro::task<> task2()
{
	co_await event;
	std::cout << "task2 executing!\n";
	co_return;
}

cppcoro::task<> setEventTask()
{
	event.set();
	co_return;
}

// This handles scheduling the tasks
cppcoro::task<> scheduler()
{
	// Run these three coroutines cooperatively
	co_await cppcoro::when_all(task1(), task2(), setEventTask());

	co_return;
}

int main()
{
	// This saves the state of the coroutine
	auto generator = GetNextNum();
	auto iter = generator.begin();
	for (int i = 0; i < 10; i++)
	{
		// Every time we *iter it'll lazily compute the value
		std::cout << *iter << "\n";
		// This updates the coroutine state
		iter++;
	}

	cppcoro::sync_wait(scheduler());

	return 0;
}
