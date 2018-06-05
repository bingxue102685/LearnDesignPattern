#pragma once
#include<iostream>
#include"head.h"

int main(void)
{
	//工厂模式
	Test* test = new FactoryTest();
	test->testfunc();


	system("pause");
	return 0;
}