#include "coordinates.h"

Coordinates::Coordinates() : Coordinates(0, 0) {}

Coordinates::Coordinates(int i, int j)
	: row_i(i), column_j(j)
{
	if (i < 0)
		throw "coordinates error : negative i";
	if (j < 0)
		throw "coordinates error : negative j";
}