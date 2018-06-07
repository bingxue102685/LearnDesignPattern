#pragma once
#include <iostream>
#include "test.h"
using namespace std;

/*
	* 模型: 现实中的租房案例
	* 租房者.租房 -> 中介.租房 -> 房东.租房
*/

/* 实现这个接口的人，都说自己可以租房 */
class RentOut
{
public:
	virtual void Rent() = 0;
};

/* 房东，拥有房子真正的出租权，所有的中介出租，都要经过房东来处理 */
class HouseHolder :public RentOut
{
public:
	void Rent();
};

/* 中介，拥有房东的租房信息，对外宣称可以租房，房客不能直接找房东租房，只能通过中介来租房 */
class HouseProxy :public RentOut
{
private:
	HouseHolder* houseHoler;
public:
	void Rent();
	/* 租房前收中介费 */
	void BeforeRent();
	/* 租房后收押金 */
	void AfterRent();
};

//测试
class ProxyPatternTest :public Test
{
public:
	void testfunc(bool isrun)
	{
		if (!isrun)
			return;
		/*初入社会的 小青年，找不到房东的直租信息，只能找中介啦*/
		RentOut* houseProxy = new HouseProxy();
		houseProxy->Rent();
	}
};