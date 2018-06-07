#pragma once
#include <iostream>
#include "test.h"
using namespace std;

/*
	* ģ��: ��ʵ�е��ⷿ����
	* �ⷿ��.�ⷿ -> �н�.�ⷿ -> ����.�ⷿ
*/

/* ʵ������ӿڵ��ˣ���˵�Լ������ⷿ */
class RentOut
{
public:
	virtual void Rent() = 0;
};

/* ������ӵ�з��������ĳ���Ȩ�����е��н���⣬��Ҫ�������������� */
class HouseHolder :public RentOut
{
public:
	void Rent();
};

/* �н飬ӵ�з������ⷿ��Ϣ���������ƿ����ⷿ�����Ͳ���ֱ���ҷ����ⷿ��ֻ��ͨ���н����ⷿ */
class HouseProxy :public RentOut
{
private:
	HouseHolder* houseHoler;
public:
	void Rent();
	/* �ⷿǰ���н�� */
	void BeforeRent();
	/* �ⷿ����Ѻ�� */
	void AfterRent();
};

//����
class ProxyPatternTest :public Test
{
public:
	void testfunc(bool isrun)
	{
		if (!isrun)
			return;
		/*�������� С���꣬�Ҳ���������ֱ����Ϣ��ֻ�����н���*/
		RentOut* houseProxy = new HouseProxy();
		houseProxy->Rent();
	}
};