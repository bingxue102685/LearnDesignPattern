#pragma once
#include <iostream>
#include "test.h"

using namespace std;
class Shape 
{
public:
	virtual void draw() = 0;
};

class Rectangle :public Shape
{
public:
	void draw();
};

class Square :public Shape
{
public:
	void draw();
};

class Circle :public Shape
{
public:
	void draw();
};

//¹¤³§Àà
class ShapeFactory
{
public:
	Shape* getShape(string shapeType);
};


//²âÊÔ
class FactoryTest :public Test
{
public:
	void testfunc(bool isrun)
	{
		if (!isrun)
			return;

		ShapeFactory* factory = new ShapeFactory();
		Shape* shape1 = factory->getShape("rectangle");
		shape1->draw();

		Shape* shape2 = factory->getShape("square");
		shape2->draw();

		Shape* shape3 = factory->getShape("circle");
		shape3->draw();
	}
};