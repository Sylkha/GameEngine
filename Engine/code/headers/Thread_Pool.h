#pragma once

#include <vector>
#include <thread>
#include <queue>
#include "Task.h"

using namespace std;
namespace gameEngine {
	class Thread_Pool {
	private:
		std::vector<std::thread> threads;
		std::queue< Task*> task_list;
		bool exit;

		void thread_loop() {
			while (!exit) {
				if (!task_list.empty()) {
					//lock l (mutex)
					auto& task = task_list.front();
					task_list.pop();
				}
				//task->run();
			}
		}
	public:
		//queue(Task* t);
	};
}