#include "FactoryPattern.h"

//工厂模式

//Rectangle
void Rectangle::draw()
{
	cout << "draw rectangle!" << endl;
}

//Square
void Square::draw()
{
	cout << "draw square!" << endl;
}

//Circle
void Circle::draw()
{
	cout << "draw circle!" << endl;
}

//Factory
Shape* ShapeFactory::getShape(string shapeType)
{
	if (shapeType == "rectangle")
	{
		return new Rectangle();
	}
	if (shapeType == "square")
	{
		return new Square();
	}
	if (shapeType == "circle")
	{
		return new Circle();
	}
	return NULL;
}