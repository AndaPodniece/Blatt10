#include "Functions.h"
#include "Aggregation.h"
#include <stdio.h>
#include <iostream>
int main()
{
	int array[] = { 4, 2, 3, 1, 5, 6 };
	int size = sizeof(array) / sizeof(array[0]);

	//1.a
	int result_lambda = aggregate<int, int>(array, size, [](int x, int y) { return x + y; });
	int sum = aggregate<int, int>(array, size);
	int result = aggregate(array, size, sumFunction<int, int>, getElement<int>);
	//1.b
	int result2 = aggregate(array, size, multFunction<int, int>, getElement<int>);
	int product = aggregate<int, int>(array, size, [](int x, int y) {return x * y; });
	//1.c
	double mean = aggregate<int, double>(array, size, [](double x, double y) { return x + y; }, [](int n) {return static_cast<double>(n);}) / size;
	double result3 = arith_mean(array, size);
	//1.d
	double minimum = min(array, size);
	int min = aggregate<int, int>(array, size, [](int min, int num) {return(min < num) ? min : num; });
	std::cout <<"sum with function: " << result << std::endl;
	std::cout << "sum with lambda: " << sum << std::endl;

	std::cout << "multiplication with function: "<< result2 << std::endl;
	std::cout << "multiplication with lambda: " << product << std::endl;

	std::cout << "avarage number with function: " << result3 << std::endl;
	std::cout << "avarage number with lambda: " << mean << std::endl;

	std::cout << "minimum value of an array with function: " << minimum << std::endl;
	std::cout << "minimum value of an array with lambda: " << min << std::endl;

	std::cout << "result_lambda: " << result_lambda << std::endl;
	return 0;
}