#pragma once
#include<iostream>
#include"head.h"

int main(void)
{
	//����ģʽ
	Test* test = new FactoryTest();
	test->testfunc(false);

	//������ģʽ
	test = new BuilderTest();
	test->testfunc(false);

	//����ģʽ
	test = new ProxyPatternTest();
	test->testfunc();


	system("pause");
	return 0;
}