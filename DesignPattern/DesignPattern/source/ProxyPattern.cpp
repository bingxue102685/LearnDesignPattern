#include "ProxyPattern.h"

//房东
void HouseHolder::Rent()
{
	cout << "I'm landlord, I'm renting the house!\n" << endl;
}

//中介
void HouseProxy::Rent()
{
	if (houseHoler == NULL)
	{
		houseHoler = new HouseHolder();
	}

	//收中介费
	BeforeRent();
	//出租
	houseHoler->Rent();
	//收押金
	AfterRent();
}

//出租之前
void HouseProxy::BeforeRent()
{
	cout << "I'm proxy, I need proxy money!\n" << endl;
}

//出租之后
void HouseProxy::AfterRent()
{
	cout << "I'm proxy, I need deposit money!\n" << endl;
}