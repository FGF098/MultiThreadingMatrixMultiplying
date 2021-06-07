#pragma once

class Coordinates
{
public:

	Coordinates();
	Coordinates(int i, int j);

	int i() const { return row_i; };
	int j() const { return column_j; };

private:

	int row_i;
	int column_j;
};