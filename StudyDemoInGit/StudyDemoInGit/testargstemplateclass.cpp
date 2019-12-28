#include "stdafx.h"
#include "testargstemplateclass.h"
#include <iostream>

// ��Ļ�������
template<typename First, typename...Rest>
struct Sum<First, Rest...>
{
    enum { value = Sum<First>::value +Sum<Rest...>::value};
};

// �ݹ���ֹ
template<typename Last>
struct Sum<Last>
{
    enum { value = sizeof(Last) };
};

void test_args_template_class()
{
    // value��ʹ�ã��������enum value�Ķ���֮��
    int size = Sum<int, double, short>::value;
    printf("size : %d \n ", size);

    using T = MakeIndexes<3>::type;  //���Ϊ struct IndexSeq<0,1,2>
    std::cout << typeid(T).name() << std::endl;

}