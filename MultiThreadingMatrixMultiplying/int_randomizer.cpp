#include "int_randomizer.h"

#include <ctime>

IntRandomizer::IntRandomizer()
{
	generator = std::mt19937(time(nullptr));
}

int IntRandomizer::rand(int till)
{
	return generator() % (till + 1);
}

int IntRandomizer::rand(int from, int till)
{
	if (till <= from)
		throw "random generator error : ";

	return generator() % (till - from + 1) + from;
}