#include "ProxyPattern.h"

//����
void HouseHolder::Rent()
{
	cout << "I'm landlord, I'm renting the house!\n" << endl;
}

//�н�
void HouseProxy::Rent()
{
	if (houseHoler == NULL)
	{
		houseHoler = new HouseHolder();
	}

	//���н��
	BeforeRent();
	//����
	houseHoler->Rent();
	//��Ѻ��
	AfterRent();
}

//����֮ǰ
void HouseProxy::BeforeRent()
{
	cout << "I'm proxy, I need proxy money!\n" << endl;
}

//����֮��
void HouseProxy::AfterRent()
{
	cout << "I'm proxy, I need deposit money!\n" << endl;
}