// StudyDemoInGit.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ServiceLocator/TestLocator.h"
#include "Factory3Mode/TestFactory.h"
#include "CommandMode/TestCommand.h"

int _tmain(int argc, _TCHAR* argv[])
{
    //TestLocator testlocator;
    //testlocator.testFun();

   // //���Լ򵥹���ģʽ
   //TestFactory testFac;
   //testFac.testSimpleFactory();
   ////���Թ���ģʽ
   //testFac.testFactory();
   ////���Գ��󹤳�ģʽ
   //testFac.testAbstractFactory();

    //��������ģʽ
    TestCommand testCmd;
    testCmd.TestFunc();

	return 0;
}

