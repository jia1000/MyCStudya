#pragma once
void test_args_template();
//���Կɱ�ģ�������
void test_args_template1();
//------���Կɱ�ģ�� ��չ��
void test_args_template2();
// չ������2 --- ʹ�ó�ʼ���б� �� ���ű��ʽ
void test_args_template3();

template <class...T>
void f(T... args);

// չ������1--- �������صĵݹ���ֹ����,ʵ�� �ɱ�ģ���չ����
void print();

template<class T, class... args>
void print(T head, args... rest);

// չ������2 --- ʹ�ó�ʼ���б� �� ���ű��ʽ
template<typename T>
void printarg(T t);

template<class... args>
void expand(args... a);



