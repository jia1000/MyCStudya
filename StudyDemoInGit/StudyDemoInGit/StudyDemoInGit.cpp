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

#include "SimpleAOP/TestAspect.h"
#include <gtest/gtest.h>

#include <thread>
#include "testmutex.h"
#include "testtimemutex.h"

int _tmain(int argc, _TCHAR* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    
    //test_mutex();
    test_time_mutex();
	return RUN_ALL_TESTS();;
}

