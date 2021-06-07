#include "matrix_part.h"

MatrixPart::MatrixPart(MatrixPart& parent, Position position)
{
	int parentHeight = parent.height();
	int parentWidth = parent.width();

	if (parentHeight < 0)
		throw "matrix part creating error : negative parent height";
	if (parentWidth < 0)
		throw "matrix part creating error : negative parent width";

	if (parentHeight < 2)
		throw "matrix part creating error : too small parent height";
	if (parentWidth < 2)
		throw "matrix part creating error : too small parent width";

	int halfHeight = parentHeight / 2;
	int halfWidth = parentWidth / 2;

	switch (position)
	{
	case Position::UP_LEFT:
		iStartIndex = 0;
		iPostEndIndex = halfHeight;
		jStartIndex = 0;
		jPostEndIndex = halfWidth;
		break;

	case Position::UP_RIGHT:
		iStartIndex = 0;
		iPostEndIndex = halfHeight;
		jStartIndex = halfWidth;
		jPostEndIndex = parentWidth;
		break;

	case Position::DOWN_LEFT:
		iStartIndex = halfHeight;
		iPostEndIndex = parentHeight;

		break;
	}
}