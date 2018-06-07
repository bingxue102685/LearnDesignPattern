#pragma once
#include<iostream>
#include"head.h"

int main(void)
{
	//工厂模式
	Test* test = new FactoryTest();
	test->testfunc(false);

	//建造者模式
	test = new BuilderTest();
	test->testfunc(false);

	//代理模式
	test = new ProxyPatternTest();
	test->testfunc();


	system("pause");
	return 0;
}