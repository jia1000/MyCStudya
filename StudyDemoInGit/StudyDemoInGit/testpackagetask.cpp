#include "stdafx.h"
#include "testpackagetask.h"
#include <iostream>
#include <thread>
#include <future>
#include <chrono>

double func(int x)
{
    printf("%s\n", __FUNCTION__);
    std::chrono::microseconds sleeptime(1000);
    std::this_thread::sleep_for(sleeptime);

    printf("%d\n", __LINE__);
    return x + 2.5;
}

void test_package_task()
{
    // ��һ����ͨ������תΪpackaged_task��ͬʱ��task�ڲ�������future
    std::packaged_task<double(int)> tsk(func);

    // ��packaged_task�У���ȡfuture�����ܷ����̺߳���ִ��֮��
    std::future<double> f = tsk.get_future();

    // �˴�����ʹ��move������ת������Ȩ�������������
    std::thread th1(std::move(tsk), 2);
    th1.detach();

    printf("get future\n");    

    double value = f.get();
    printf("value : %.3f\n", value);
}