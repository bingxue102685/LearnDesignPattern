#pragma once
#include<iostream>
#include"head.h"

int main(void)
{
	//����ģʽ
	Test* test = new FactoryTest();
	test->testfunc();


	system("pause");
	return 0;
}