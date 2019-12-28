#pragma once
/*
���Ե��ǡ��ɱ����ģ�庯����
*/
////////��ʽ1�� �ݹ� + �ػ���ʽ��չ��������///////////////////////////////////
void test_args_template_class();

//  ����
template<typename... Args>
struct Sum
{

};

//////////��ʽ2���̳з�ʽ��չ��������//////////////////////////
//�������еĶ���
template<int...>
struct IndexSeq {};

//�̳з�ʽ����ʼչ��������
template<int N, int ... Indexes>
struct MakeIndexes : MakeIndexes<N - 1, N - 1, Indexes...> {};

//ģ���ػ�����ֹչ��������������
template<int... Indexes>
struct MakeIndexes<0, Indexes...> {
    typedef IndexSeq<Indexes...> type;
};