#pragma once

#include "coordinates.h"

class Size : public Coordinates
{
public:

	Size();
	Size(int i, int j);

	int power() const { return power_value; };
	int pow2size() const { return pow2size_value; };

private:

	int power_value;
	int pow2size_value;
};