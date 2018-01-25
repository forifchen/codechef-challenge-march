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
		int rows() { return _rows; }
		int cols() { return _cols; }
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

extern Matrix<int> matrix;
void readMatrix();
int getNumberOfOnes();
int minimumBandFor(size_t ones);
