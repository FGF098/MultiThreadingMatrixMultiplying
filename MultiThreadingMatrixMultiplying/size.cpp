#include "size.h"

Size::Size() : Size(1, 1) {}

Size::Size(int i, int j) : Coordinates(i, j)
{
	if (i == 0)
		throw "Size can't be zero (i-dimention)";
	if (j == 0)
		throw "Size can't be zero (j-dimention)";

	int max;

	if (i > j)
		max = i;
	else max = j;

	power_value = 0;
	pow2size_value = 1;

	while (pow2size_value < max)
	{
		pow2size_value *= 2;
		power_value++;
	}
}