#include "stdafx.h"
#include "testmutex.h"

void test_mutex()
{
    testmutex t(4);
    //t.both(32, 23);

    std::thread th(&testmutex::both, &t, 32, 23);
    th.join();
}

testmutex::testmutex(int x = 0)
    : i(x)
{

}
void testmutex::mul(int x)
{
    printf("%s\n", __FUNCTION__);
    std::lock_guard<std::recursive_mutex> lk(recursivemutex);
    // û��ʹ��recursive_mutexʱ�� ��ݹ���û�����mutex�� 
    // vs���ڴ˴���������.������ʾ�������������ǣ��޷�����ԭ��
    printf("%d\n", __LINE__);
    i *= x;
}

void testmutex::div(int x)
{
    printf("%s\n", __FUNCTION__);
    std::lock_guard < std::recursive_mutex > lk(recursivemutex);
    if (x == 0) return;
    i /= x;
}

void testmutex::both(int x, int y)
{
    printf("%s\n", __FUNCTION__);
    std::lock_guard<std::recursive_mutex> lk(recursivemutex);
    printf("%d\n", __LINE__);
    mul(x);
    printf("%d\n", __LINE__);
    div(y);
    printf("%d\n", __LINE__);
}
