#include <assert.h>
#include <tuple>

#include "main.h"
#include "Matrix.h"


using namespace std;

int main()
{
	cout << "Homework 6: Matrix" << endl << endl;

	// Creating and filling matrix.
	cout << "Filling matrix..." << endl;
	Matrix<int, 0> matrix;
	for (int i = 0; i < 10; ++i)
		matrix(i,i) = i;

	for (int i = 9; i >= 0; --i)
		matrix(9 - i,i) = i;


	// Output of a matrix fragment (from (1,1) to (8,8)).
	cout << "Output of a matrix fragment (from (1,1) to (8,8))" << endl;
	for (int i = 1; i < 9; ++i)
	{
		for (int j = 1; j < 9; ++j)
		{
			std::cout << matrix(i,j) << ' ';
		}
		std::cout << '\n';
	}


	// Output the number of occupied cells.
	cout << "Number of occupied cells: " << matrix.Size() << endl << endl;


	// Output information about occupied cells in format position: value.
	cout << "Occupied cells in format position: value" << endl;
	for (auto c : matrix)
	{
		int x, y, v;
		tie(x, y, v) = c;
		cout << x << ',' << y << ": " << v << endl;
	}

	// CheckAsExplained();

	return 0;
}

void CheckAsExplained()
{
	Matrix<int, -1> matrix;

	auto a = matrix(0, 0);
	assert(a == -1);
	assert(matrix.Size() == 0);

	matrix(100, 100) = 314;
	assert(matrix(100, 100) == 314);
	assert(matrix.Size() == 1);

	for (auto c : matrix)
	{
		int x, y, v;
		tie(x, y, v) = c;
		cout << x << ' ' << y << ' ' << v << endl;
	}

	matrix(10, 1) = 2;
	matrix(1, 10) = 3;
	assert(matrix(10, 1) == 2);
	assert(matrix(1, 10) == 3);
	assert(matrix(10, 10) == -1);
	assert(matrix.Size() == 3);
}
