#include "BuilderPattern.h"



//product
void Menu::SetMenuName(string name)
{
	menuName = name;
}

void Menu::AddItem(string iterm)
{
	menuList.push_back(iterm);
}

void Menu::ShowItems()
{
	string menuTitle = menuName + "�ĵ�ǰ�˵�";
	cout << menuTitle.c_str() << endl;
	for each (string item in menuList)
	{
		cout << item.c_str()<< endl;
	}
	cout << "\n" << endl;
}


//KFC builder
KFCBuilder::KFCBuilder()
{
	kfcMenu = new Menu();
	kfcMenu->SetMenuName("KFC");
}

void KFCBuilder::AddDrink()
{
	kfcMenu->AddItem("���¿���");
}

void KFCBuilder::AddEat()
{
	kfcMenu->AddItem("����");
}

Menu* KFCBuilder::GetMenu()
{
	return kfcMenu;
}

//MDL builder
MDLBuilder::MDLBuilder()
{
	mdlMenu = new Menu();
	mdlMenu->SetMenuName("����");
}
void MDLBuilder::AddDrink()
{
	mdlMenu->AddItem("�ɿڿ���");
}
void MDLBuilder::AddEat()
{
	mdlMenu->AddItem("ը��");
}
Menu* MDLBuilder::GetMenu()
{
	return mdlMenu;
}


void Director::Construct(Builder* builder)
{
	builder->AddEat();
	builder->AddDrink();
}