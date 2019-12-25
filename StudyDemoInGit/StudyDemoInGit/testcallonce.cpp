#include "stdafx.h"
#include "testcallonce.h"

#include <thread>
#include <mutex>

std::once_flag flag1;
std::once_flag flag2;

void test_call_once()
{
    std::thread th1(do_once_funmction);
    std::thread th2(do_once_funmction);

    th1.join();
    th2.join();

    std::thread th3(do_once_member_funmction);
    std::thread th4(do_once_member_funmction);

    th3.join();
    th4.join();
}
// ���Ե��ö�������----------------------------
void once_function()
{
    printf("Called function once.\n");
}
void do_once_funmction()
{
    std::call_once(flag1, once_function);
}

// ���Ե�����ĳ�Ա����----------------------------
void A::once_func()
{
    printf("Called member function once.\n");
}

void do_once_member_funmction()
{
    A a;
    std::call_once(flag2, &A::once_func, a);
}