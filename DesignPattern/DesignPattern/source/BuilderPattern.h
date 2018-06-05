#pragma once
#include <iostream>
#include <vector>
#include "test.h"

using namespace std;
//其实到现在还没有搞懂建造者模式有什么好处，跟工厂模式的区别是什么

/*
	* 模型如下：
	* 菜单：


*/

//product
class Menu
{
private:
	vector<string> menuList;
	string menuName;
public:
	void SetMenuName(string name);
	void AddItem(string item);
	void ShowItems();
};

//bulilder
class Builder
{
public:
	virtual void AddDrink() = 0;
	virtual void AddEat() = 0;
	virtual Menu* GetMenu() = 0;
};

//KFC builder
class KFCBuilder : public Builder
{
private:
	Menu* kfcMenu;
public:
	KFCBuilder();
	void AddDrink();
	void AddEat();
	Menu* GetMenu();
};

//MDL builder
class MDLBuilder :public Builder
{
private:
	Menu* mdlMenu;
public:
	MDLBuilder();
	void AddDrink();
	void AddEat();
	Menu* GetMenu();
};

//Director
class Director
{
public:
	void Construct(Builder* builder);
};

//测试
class BuilderTest :public Test
{
public:
	void testfunc(bool isrun)
	{
		if (!isrun)
			return;

		Director* director = new Director();
		Builder* builder1 = new MDLBuilder();
		director->Construct(builder1);
		Menu* menu1 = builder1->GetMenu();
		menu1->ShowItems();

		Builder* builder2 = new KFCBuilder();
		director->Construct(builder2);
		Menu* menu2 = builder2->GetMenu();
		menu2->ShowItems();
	}
};