#pragma once
#include <iostream>
#include "test.h"
using namespace std;
/*
	����ģʽ
	�ŵ㣺
	��1������ģʽ�ṩ�˹�����ص��㷨��İ취��������ĵȼ��ṹ������һ���㷨����Ϊ�塣ǡ��ʹ�ü̳п��԰ѹ����Ĵ����Ƶ��������棬�Ӷ���������ظ���

������2��ʹ�ò���ģʽ���Ա���ʹ�ö�������(if-else)��䡣����������䲻��ά�������Ѳ�ȡ��һ���㷨���ȡ��һ����Ϊ���߼����㷨����Ϊ���߼������һ��ͳͳ����һ����������������棬��ʹ�ü̳еİ취��Ҫԭʼ�����
	
	ȱ�㣺
	��1���ͻ��˱���֪�����еĲ����࣬�����о���ʹ����һ�������ࡣ�����ζ�ſͻ��˱��������Щ�㷨�������Ա���ʱѡ��ǡ�����㷨�ࡣ����֮������ģʽֻ�����ڿͻ���֪���㷨����Ϊ�������

	��2�����ڲ���ģʽ��ÿ������Ĳ���ʵ�ֶ�������װ��Ϊ�࣬�����ѡ�Ĳ��Ժܶ�Ļ�����ô�������Ŀ�ͻ�ܿɹۡ�

	������ָ��������ǣ�

	ģ�ͣ� �������������ļӡ�������
*/

class Strategy
{
public:
	virtual int DoOperation(int num1, int num2) = 0;
};

class AddOperation :public Strategy
{
public:
	int DoOperation(int num1, int num2);
};

class SubOperation :public Strategy
{
public:
	int DoOperation(int num1, int num2);
};

class MutilOperation :public Strategy
{
public:
	int DoOperation(int num1, int num2);
};

class Context
{
private:
	Strategy * strategy;
public:
	Context(Strategy * strategy)
	{
		this->strategy = strategy;
	}

	int executeStrategy(int num1, int num2)
	{
		return strategy->DoOperation(num1, num2);
	}

};

//test
class StartegyPatternTest :public Test
{
public:
	void testfunc(bool isrun)
	{
		if (!isrun)
			return;

		Context* context = new Context(new AddOperation()); 
		cout << context->executeStrategy(1, 2) << endl;

		context = new Context(new SubOperation());
		cout << context->executeStrategy(1, 2) << endl;

		context = new Context(new MutilOperation());
		cout << context->executeStrategy(1, 2) << endl;
	}

};