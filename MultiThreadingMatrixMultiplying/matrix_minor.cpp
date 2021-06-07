#include "matrix_minor.h"

/*
template<typename Value>

MatrixMinor<Value>::MatrixMinor(const Matrix<Value>& current) 
	: base(current), iFrom(0), iTill(current.pow2size), jFrom(0), jTill(current.pow2size)
{ }

template<typename Value>

MatrixMinor<Value>::MatrixMinor(const MatrixMinor<Value>& parent, Position position) 
	: base(parent.base)
{
	if (parent.iDiff() == 1)
		throw "matrix minor part creating error : too small parent";

	int halfSize = parent.iDiff() / 2;

	switch (position)
	{
	case Position::UP_LEFT:
		iFrom = parent.iFrom;
		iTill = parent.iFrom + halfSize;
		jFrom = parent.jFrom;
		jTill = parent.jFrom + halfSize;
		break;
	case Position::UP_RIGHT:
		iFrom = parent.iFrom;
		iTill = parent.iFrom + halfSize;
		jFrom = parent.jFrom + halfSize;
		jTill = parent.jTill;
		break;
	case Position::DOWN_LEFT:
		iFrom = parent.iFrom + halfSize;
		iTill = parent.iTill;
		jFrom = parent.jFrom;
		jTill = parent.jFrom + halfSize;
		break;
	case Position::DOWN_RIGHT:
		iFrom = parent.iFrom + halfSize;
		iTill = parent.iTill;
		jFrom = parent.jFrom + halfSize;
		jTill = parent.jTill;
		break;
	default:
		throw "matrix minor creating error : invalid position";
		break;
	}
}
*/