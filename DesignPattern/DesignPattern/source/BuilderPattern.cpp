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
	string menuTitle = menuName + "的当前菜单";
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
	kfcMenu->AddItem("百事可乐");
}

void KFCBuilder::AddEat()
{
	kfcMenu->AddItem("汉堡");
}

Menu* KFCBuilder::GetMenu()
{
	return kfcMenu;
}

//MDL builder
MDLBuilder::MDLBuilder()
{
	mdlMenu = new Menu();
	mdlMenu->SetMenuName("麦当劳");
}
void MDLBuilder::AddDrink()
{
	mdlMenu->AddItem("可口可乐");
}
void MDLBuilder::AddEat()
{
	mdlMenu->AddItem("炸鸡");
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