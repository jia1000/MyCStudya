// StudyDemoInGit.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ServiceLocator/TestLocator.h"
#include "Factory3Mode/TestFactory.h"
#include "CommandMode/TestCommand.h"

#include "ThreadPool/TestThreadPool.h"

//void test()
//{
//    //TestLocator testlocator;
//    //testlocator.testFun();
//
//    // //���Լ򵥹���ģʽ
//    //TestFactory testFac;
//    //testFac.testSimpleFactory();
//    ////���Թ���ģʽ
//    //testFac.testFactory();
//    ////���Գ��󹤳�ģʽ
//    //testFac.testAbstractFactory();
//
//    //��������ģʽ
//    //TestCommand testCmd;
//    //testCmd.TestFunc();
//}
int _tmain(int argc, _TCHAR* argv[])
{
    TestThreadPoolFunction();

	return 0;
}

