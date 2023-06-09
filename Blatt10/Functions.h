#pragma once
#include "Aggregation.h"
#include <stdexcept>
#include <iostream>
using namespace std;

//1.a
template<class S, class T>
T sumFunction(T x, T y)
{
	return x + y;
}

//1.b:
template<class S, class T>
T multFunction(T x, T y)
{
	return x * y;
}
//1.c:
double arith_mean(int array[], int size)
{
	if (size > 0)
	{
		int sum = aggregate<int, int>(array, size);
		double mean = static_cast<double>(sum) / size;
		return mean;
	}
}
//1.d:
template<class T>
T min(T array[], int size)
{
	T min = aggregate<int, int>(array, size);
	for (unsigned int i = 0; i < size; i++)
	{
		if (array[i] < min)
			min = array[i];
	}
	return min;
}

template<class S>
int getElement(S x)
{
	return x;
}
