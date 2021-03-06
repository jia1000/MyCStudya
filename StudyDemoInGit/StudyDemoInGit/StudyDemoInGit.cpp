// StudyDemoInGit.cpp : 定义控制台应用程序的入口点。
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
//    // //测试简单工厂模式
//    //TestFactory testFac;
//    //testFac.testSimpleFactory();
//    ////测试工厂模式
//    //testFac.testFactory();
//    ////测试抽象工厂模式
//    //testFac.testAbstractFactory();
//
//    //测试命令模式
//    //TestCommand testCmd;
//    //testCmd.TestFunc();
//}

#include "SimpleAOP/TestAspect.h"
#include <gtest/gtest.h>

#include <thread>
#include "testmutex.h"
#include "testtimemutex.h"
#include "testconditionvariable.h"
#include "testcallonce.h"
#include "testpackagetask.h"
#include "testsharedfuture.h"
#include "testargstemplate.h"
#include "testargstemplateclass.h"
#include "testdllhelp.h"

int _tmain(int argc, _TCHAR* argv[])
{
    testing::InitGoogleTest(&argc, argv);

    
    //test_mutex();
    //test_time_mutex();
    //test_conditionvariable();
    //test_call_once();
    //test_package_task();
    //test_shared_future();
    //test_args_template();
    //test_args_template_class();
    //test_template_factory();
    test_dll_help();

	return RUN_ALL_TESTS();;
}

