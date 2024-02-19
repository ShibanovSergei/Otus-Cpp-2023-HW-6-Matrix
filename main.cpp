#include <assert.h>
#include <tuple>

#include "main.h"
#include "Matrix.h"


using namespace std;

int main()
{
	cout << "Hi all from CMake." << endl;

	CheckAsExplained();

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

	//for (auto c : matrix)
	//{
	//	int x, y, v;
	//	std::tie(x, y, v) = c;
	//	std::cout << x << y << v << std::endl;
	//}

	matrix(10, 1) = 2;
	matrix(1, 10) = 3;
	assert(matrix(10, 1) == 2);
	assert(matrix(1, 10) == 3);
	assert(matrix(10, 10) == -1);
	assert(matrix.Size() == 3);
}
