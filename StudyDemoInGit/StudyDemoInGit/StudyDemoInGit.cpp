// StudyDemoInGit.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ServiceLocator/TestLocator.h"
#include "Factory3Mode/TestFactory.h"

int _tmain(int argc, _TCHAR* argv[])
{
    //TestLocator testlocator;
    //testlocator.testFun();

    //���Լ򵥹���ģʽ
   TestFactory testFac;
   testFac.testSimpleFactory();
   //���Թ���ģʽ
   testFac.testFactory();
   //���Գ��󹤳�ģʽ
   testFac.testAbstractFactory();

	return 0;
}

