#include "StrategyPattern.h"

int AddOperation::DoOperation(int num1, int num2)
{
	return num1 + num2;
}


int SubOperation::DoOperation(int num1, int num2)
{
	return num1 - num2;
}

int MutilOperation::DoOperation(int num1, int num2)
{
	return num1 * num2;
}