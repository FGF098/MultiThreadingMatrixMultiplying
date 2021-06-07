#pragma once

#include <random>

class IntRandomizer
{
public:

	IntRandomizer();

	int rand(int till);
	int rand(int from, int till);

private:

	std::mt19937 generator;
};