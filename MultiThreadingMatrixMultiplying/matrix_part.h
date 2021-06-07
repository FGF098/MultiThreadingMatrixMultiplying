#pragma once

#include "position.h"

#include <vector>
using namespace std;

/// <summary>
/// part of matrix (coordinates of start/end and reference to matrix)
/// </summary>
class MatrixPart
{
public:
	
	MatrixPart(MatrixPart& parent, Position position);

	int iStart() const { return iStartIndex; };
	int iEnd() const { return iPostEndIndex; };

	int jStart() const { return jStartIndex; };
	int jEnd() const { return jPostEndIndex; };

	int height() const { return iPostEndIndex - iStartIndex; };
	int width() const { return jPostEndIndex - jStartIndex; };

private:

	int iStartIndex;
	int iPostEndIndex;

	int jStartIndex;
	int jPostEndIndex;
};