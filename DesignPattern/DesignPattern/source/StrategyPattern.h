#pragma once
#include <iostream>
#include "test.h"
using namespace std;
/*
	策略模式
	优点：
	（1）策略模式提供了管理相关的算法族的办法。策略类的等级结构定义了一个算法或行为族。恰当使用继承可以把公共的代码移到父类里面，从而避免代码重复。

　　（2）使用策略模式可以避免使用多重条件(if-else)语句。多重条件语句不易维护，它把采取哪一种算法或采取哪一种行为的逻辑与算法或行为的逻辑混合在一起，统统列在一个多重条件语句里面，比使用继承的办法还要原始和落后。
	
	缺点：
	（1）客户端必须知道所有的策略类，并自行决定使用哪一个策略类。这就意味着客户端必须理解这些算法的区别，以便适时选择恰当的算法类。换言之，策略模式只适用于客户端知道算法或行为的情况。

	（2）由于策略模式把每个具体的策略实现都单独封装成为类，如果备选的策略很多的话，那么对象的数目就会很可观。

	跟函数指针的区别是？

	模型： 计算两个整数的加、减、乘
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