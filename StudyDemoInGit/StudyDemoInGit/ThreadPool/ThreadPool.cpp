#include "stdafx.h"

#include "ThreadPool.h"

ThreadPool::ThreadPool()
	: _running(false)
	, _max_queue_size(10)
{
}

ThreadPool::~ThreadPool()
{
	if (_running) {
		stop();
	}
}

void ThreadPool::start(int num_threads)
{
	_running = true;
	_threads.reserve(num_threads);

	for (int Index = 0; Index < num_threads ; Index++) {
		_threads.push_back(std::thread(&ThreadPool::runInThread, this));
	}
}

void ThreadPool::stop()
{
	{
		std::unique_lock<std::mutex> lock(_mutex);
		// ��ʶλ��Ϊfalse
		_running = false;
		// ʹ�÷ǿ���������,֪ͨȫ��
		_notEmpty.notify_all();
	}
	// �ر��߳�
	for (size_t Index = 0; Index < _threads.size(); Index++) {
		_threads[Index].join();
	}
}

void ThreadPool::run(const Task& f)
{
	// ���û�������߳������������ǵ��̣߳�ֱ��ִ������
	if (_threads.empty()) {
		f();
	}
	std::unique_lock<std::mutex> lock(_mutex);
	while (isFull()) {
		// �����ȣ����ǻ��ͷ�mutex
		_notFull.wait(lock);
	}
	_queue.push_back(f);
	_notEmpty.notify_one();
}

void ThreadPool::setMaxQueueSize(int max_queue_size)
{
	_max_queue_size = max_queue_size;
}

bool ThreadPool::isFull()
{
	return _max_queue_size > 0 && _queue.size() >= _max_queue_size;
}

void ThreadPool::runInThread()
{
	try {
		while (_running)
		{
			Task task = take();
			if (task) {
				task();
			}
		}
	}
	catch (const std::exception& e) {
		printf("exception reason1 : %s\n", e.what());		
	}
	catch (...) {
		printf("exception\n");
	}
}

ThreadPool::Task ThreadPool::take()
{
	std::unique_lock<std::mutex> lock(_mutex);
	// ���ȶ���������
	while (_queue.empty() && _running)
	{
		// �����ȣ����ǻ��ͷ�mutex
		_notEmpty.wait(lock);
	}

	Task task;
	// ȡ������
	if (!_queue.empty()) {
		task = _queue.front();
		_queue.pop_front();
	}
	// ȡ������󣬶���������������񣬿���ʹ�÷�������������֪ͨ
	if (_queue.size() > 0) {
		_notFull.notify_one();
	}
	return task;
}
