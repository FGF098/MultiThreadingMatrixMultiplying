#pragma once

#include "size.h"

#include <vector>
using namespace std;

class MatrixInt
{
public:

	/// <summary>
	/// creating zero-matrix with getted size
	/// </summary>
	/// <param name="size">size of matrixes (common and pow2-squared)</param>
	MatrixInt(Size size);

	/// <summary>
	/// getter and setter for matrix elements;
	/// if out of range - const char* throw error
	/// </summary>
	/// <param name="coordinates">coordinates of using element</param>
	/// <returns>reference of element : can change, but not delete</returns>
	int& operator[] (Coordinates coordinates);

	/// <summary>
	/// getter only for matrix elements;
	/// if out of range - const char* throw error
	/// </summary>
	/// <param name="coordinates">coordinates of using element</param>
	/// <returns>copy of element value (not an element)</returns>
	int operator[] (Coordinates coordinates) const;

	// can't using operator overloading - same signature

	/// <summary>
	/// classic O(n^3) matrix multiplying
	/// for i=0,n { 
	/// for j=0,n {
	/// res[i,j] = 0 ; 
	/// for k=0,n {
	/// res+=first[i,k]+second[k,j] }}}
	/// </summary>
	/// <param name="first">matrix m*n</param>
	/// <param name="second">matrix n*p</param>
	/// <param name="result">matrix m*p</param>
	static void ClassicCycle(const MatrixInt& first, const MatrixInt& second, MatrixInt& result);

	/// <summary>
	/// recursive variant of classic matrix multiplying (for pow2-sized matrixes)
	/// first = { a11, a12, a21, a22 }
	/// second = { b11, b12, b21, b22 }
	/// result = { c11, c12, c21, c22 }
	/// </summary>
	/// <param name="first">matrix m*n, pow2size k</param>
	/// <param name="second">matrix n*p, pow2size k</param>
	/// <param name="result">matrix m*p, pow2size k</param>
	static void ClassicRecursive(const MatrixInt& first, const MatrixInt& second, MatrixInt& result);

	/// <summary>
	/// recursive variant of classic matrix multiplying (for pow2-sized matrixes)
	/// first = { a11, a12, a21, a22 }
	/// second = { b11, b12, b21, b22 }
	/// result = { c11, c12, c21, c22 }
	/// </summary>
	/// <param name="first">matrix m*n, pow2size k</param>
	/// <param name="second">matrix n*p, pow2size k</param>
	/// <param name="result">matrix m*p, pow2size k</param>
	static void StrassenMultiplying(const MatrixInt& first, const MatrixInt& second, MatrixInt& result);

	/// <summary>
	/// classic O(n^3) matrix multiplying
	/// for i=0,n { 
	/// for j=0,n {
	/// res[i,j] = 0 ; 
	/// for k=0,n {
	/// res+=first[i,k]+second[k,j] }}}
	/// </summary>
	/// <param name="first">matrix m*n</param>
	/// <param name="second">matrix n*p</param>
	/// <param name="result">matrix m*p</param>
	static void ClassicCycle(const MatrixInt& first, const MatrixInt& second);

	/// <summary>
	/// recursive variant of classic matrix multiplying (for pow2-sized matrixes)
	/// first = { a11, a12, a21, a22 }
	/// second = { b11, b12, b21, b22 }
	/// result = { c11, c12, c21, c22 }
	/// </summary>
	/// <param name="first">matrix m*n, pow2size k</param>
	/// <param name="second">matrix n*p, pow2size k</param>
	/// <param name="result">matrix m*p, pow2size k</param>
	static void ClassicRecursive(const MatrixInt& first, const MatrixInt& second);

	/// <summary>
	/// recursive variant of classic matrix multiplying (for pow2-sized matrixes)
	/// first = { a11, a12, a21, a22 }
	/// second = { b11, b12, b21, b22 }
	/// result = { c11, c12, c21, c22 }
	/// </summary>
	/// <param name="first">matrix m*n, pow2size k</param>
	/// <param name="second">matrix n*p, pow2size k</param>
	/// <param name="result">matrix m*p, pow2size k</param>
	static void StrassenMultiplying(const MatrixInt& first, const MatrixInt& second);

	/// <summary>
	/// size of matrix (common and pow2-sized)
	/// </summary>
	Size _size() const { return size; };

private:

	/// <summary>
	/// size of matrix (common and pow2-sized)
	/// </summary>
	Size size;

	/// <summary>
	/// matrix values (pow2-sized)
	/// </summary>
	vector<vector<int>> value;
};