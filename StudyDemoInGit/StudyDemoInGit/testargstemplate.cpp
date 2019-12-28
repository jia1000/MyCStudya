#include "stdafx.h"
#include "testargstemplate.h"
#include <iostream>

void test_args_template()
{
    test_args_template1();
    test_args_template2();
    test_args_template3();
}

void test_args_template1()
{
    f();                //0
    f(1, 2);            //2
    f(1, 2.5, "hello"); //3
}

//���Կɱ�ģ�������
template <class...T>
void f(T... args)
{
    printf("%d\n", sizeof...(args));
}

//------���Կɱ�ģ�� ��չ�� -------------------------------
void test_args_template2()
{
    print(1, 2, 3, 4);
}
// չ������1--- �������صĵݹ���ֹ����,ʵ�� �ɱ�ģ���չ����
void print()
{
    printf("empty\n");
}

template<class T, class... args>
void print(T head, args... rest)
{
    std::cout << "parameter " << head << std::endl;
    print(rest...);
}

// չ������2 --- ʹ�ó�ʼ���б� �� ���ű��ʽ
void test_args_template3()
{
    expand(1, 2, 3, "hello");
}

// չ������2 --- ʹ�ó�ʼ���б� �� ���ű��ʽ
template<typename T>
void printarg(T t)
{
    std::cout << t << std::endl;
}
template<class... args>
void expand(args... a)
{
    // 
    int initialize_arr[] = { (printarg(a), 66)... };
}