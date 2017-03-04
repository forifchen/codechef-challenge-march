#include <iostream>
#include <vector>
template<typename T>
struct Matrix
{
	public:
		typedef T value_type;
		Matrix(size_t r = 0, size_t c = 0) : 
			data(std::vector<T>(r*c)),
			_rows(r), _cols(c)
		{
		}
		size_t rows() { return _rows; }
		size_t cols() { return _cols; }
		bool exists(size_t r, size_t c)
		{
			return r < _rows && c < _cols;
		}
		T& operator()(size_t r, size_t c)
		{
			return data[r*_cols + c];
		}
		T operator()(size_t r, size_t c) const
		{
			return data[r*_cols + c];
		}

	private:
		std::vector<T> data;
		size_t _rows, _cols;
};

Matrix<int> matrix;

void readMatrix()
{
	int dimension;
	std::cin >> dimension;
	matrix = Matrix<int>(dimension, dimension);
	for (int r = 0; r < dimension; ++ r)
	{
		for (int c = 0; c < dimension; ++ c)
		{
			std::cin >> matrix(r, c);
		}
	}
}

int getNumberOfOnes()
{
	int number = 0;
	for (size_t r = 0; r < matrix.rows(); ++ r)
		for (size_t c = 0; c < matrix.cols(); ++ c)
			if (matrix(r, c))
			{
				++ number;
			}
	return number;
}

int minimumBandFor(size_t ones)
{
	if (ones <= matrix.rows()) return 0;
	ones -= matrix.rows();
	size_t diag = matrix.rows() - 1;
	while (ones > diag*2)
	{
		ones -= diag*2;
		-- diag;
	}
	return matrix.rows() - diag;
}

int main()
{
	int number_scenarios;
	std::cin >> number_scenarios;
	while (number_scenarios --)
	{
		readMatrix();
		std::cout << minimumBandFor( getNumberOfOnes() ) << "\n";
	}
}
