#include "matrix_int.h"

MatrixInt::MatrixInt(Size _size) : size(_size)
{
	int pow2size = size.pow2size();

	value = vector<vector<int>>(pow2size, vector<int>(pow2size, 0));
}

int& MatrixInt::operator[] (Coordinates coordinates)
{
	if (coordinates.i() < size.i() && coordinates.j() < size.j())
		return value[coordinates.i()][coordinates.j()];
	else throw "matrix element error : coordinates out of range";
}

int MatrixInt::operator[] (Coordinates coordinates) const
{
	if (coordinates.i() < size.i() && coordinates.j() < size.j())
		return value[coordinates.i()][coordinates.j()];
	else throw "matrix element error : coordinates out of range";
}

void MatrixInt::ClassicCycle(const MatrixInt& first, const MatrixInt& second, MatrixInt& result)
{
	bool same_inner = first.size.j() == second.size.i();
	bool same_outer = result.size.i() == first.size.i() && result.size.j() == second.size.j();

	if (same_inner && same_outer)
	{
		int i, j, k;

		for (i = 0; i < first.size.i(); i++)
			for (j = 0; j < second.size.j(); j++)
			{
				result[{i, j}] = 0;
				for (k = 0; k < first.size.j(); k++)
					result[Coordinates(i, j)] = first[Coordinates(i, k)] * second[{k, j}];
			}
	}
	else throw "matrix classic cycle error : different sizes";
}

void MatrixInt::ClassicRecursive(const MatrixInt& first, const MatrixInt& second, MatrixInt& result)
{

}

void MatrixInt::StrassenMultiplying(const MatrixInt& first, const MatrixInt& second, MatrixInt& result)
{

}

