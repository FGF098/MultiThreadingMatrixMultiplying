#include "matrix.h"

/*Size::Size(int _rows, int _cols) : rows(_rows), cols(_cols)
{
	if (rows < 0)
		throw "Size creating error : row size below zero";
	if (cols < 0)
		throw "Size creating error : cols size below zero";
}

int getNextPow2(int number)
{
	if (number <= 0)
		throw "get next pow 2 error : can' find for negative";

	int result = 1;

	while (number < result)
		result *= 2;

	return result;
}

template <typename Value>

Matrix<Value>::Matrix(Size matrixSize)
{
	int max;

	if (matrixSize.iSize() > matrixSize.jSize())
		max = matrixSize.iSize();
	else max = matrixSize.jSize();

	pow2size = getNextPow2(max);

	value = vector<vector<Value*>>(pow2size, vector<Value*>(pow2size, nullptr));
}

template <typename Value>

Matrix<Value>::Matrix(Size matrixSize, int _pow2Size) : pow2size(_pow2Size)
{
	if (pow2Size <= 0)
		throw "matrix by pow 2 size creating error : pow 2 size non-positive";
	if (pow2Size % 2 != 0)
		throw "matrix by pow 2 size creating error : pow 2 size isn't pow 2"

	int max;

	if (matrixSize.iSize() > matrixSize.jSize())
		max = matrixSize.iSize();
	else max = matrixSize.jSize();

	if (max > pow2Size)
		throw "matrix by pow 2 size creating error : expected size bigger than getted";

	value = vector<vector<Value*>>(pow2size, vector<Value*>(pow2size, nullptr));
}

template <typename Value>

void Matrix<Value>::setValue(Value& _value, int i, int j)
{
	if (i < 0)
		throw "matrix set value error : i can't be negative";
	if (j < 0)
		throw "matrix set value error : j can't be negative";
	if (i >= size.iSize())
		throw "matrix set value error : i overflow";
	if (j >= size.jSize())
		throw "matrix set value error : j overflow";

	value[i][j] = _value;
}

template <typename Value>

Matrix<Value> Matrix<Value>::operator*(const Matrix<Value>& second) const
{
	int first_size = size.iSize();
	int second_size = second.size.jSize();

	if (size.jSize() != second.size.iSize())
		throw "matrix multipying error : ";

	Size result_size(first_size, second_size);

	Matrix<Value> result(result_size);

	int inner_size = size.jSize();

	int i, j, k;
	Value* temp;

	for (i = 0; i < first_size; i++)
		for (j = 0; j < second_size; j++)
		{
			temp = new Value;

			for (k = 0; k < inner_size; k++)
				*temp += *(value[i][k]) * *(second.value[k][j]);

			result.value[i][j] = temp;
		}

	return result;
}

#include "matrix_minor.h"

template <typename Value>

Matrix<Value> Matrix<Value>::StrassenMultiplying(const Matrix<Value>& first, const Matrix<Value>& second)
{
	if (first.pow2size != second.pow2size)
		throw "matrix Strassen multiplying error : different pow 2 sizes";

	int first_size = first.size.iSize();
	int second_size = second.size.jSize();

	if (size.jSize() != second.size.iSize())
		throw "matrix Strassen multipying error : different inner size";

	Size result_size(first_size, second_size);

	Matrix<Value> result(result_size, first.pow2size);

	MatrixMinor<Value> first_full(first);
	MatrixMinor<Value> second_full(second);
	MatrixMinor<Value> result_full(result);

	StrassenMultiplying(first_full, second_full, result_full);

	return result;
}

template <typename Value>

void Matrix<Value>::StrassenMultiplying(const MatrixMinor<Value>& first, const MatrixMinor<Value>& second, const MatrixMinor<Value>& result)
{
	if (first.iDiff() == 1)
		*(result.base.value[result.iFrom][result.iTill]) = *(first.base.value[first.iFrom][first.iTill]) * *(second.base.value[second.iFrom][second.iTill]);
	else
	{
		MatrixMinor<Value> first_up_left(first, Position::UP_LEFT);
		MatrixMinor<Value> first_up_right(first, Position::UP_RIGHT);
		MatrixMinor<Value> first_down_left(first, Position::DOWN_LEFT);
		MatrixMinor<Value> first_down_right(first, Position::DOWN_RIGHT);

		MatrixMinor<Value> second_up_left(second, Position::UP_LEFT);
		MatrixMinor<Value> second_up_right(second, Position::UP_RIGHT);
		MatrixMinor<Value> second_down_left(second, Position::DOWN_LEFT);
		MatrixMinor<Value> second_down_right(second, Position::DOWN_RIGHT);

		MatrixMinor<Value> result_up_left(result, Position::UP_LEFT);
		MatrixMinor<Value> result_up_right(result, Position::UP_RIGHT);
		MatrixMinor<Value> result_down_left(result, Position::DOWN_LEFT);
		MatrixMinor<Value> result_down_right(result, Position::DOWN_RIGHT);


	}
}*/