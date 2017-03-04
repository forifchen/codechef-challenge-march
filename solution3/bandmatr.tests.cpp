#include "bandmatr.hpp"
#include <gtest/gtest.h>

TEST(DISABLED_bandmatr, reading)
{
	EXPECT_NO_THROW (readMatrix());
}

TEST(bandmatr, getNumberOfOnes)
{
	matrix = Matrix<int>(2, 2);
	for (size_t i = 0; i < 2; ++ i)
		for (size_t j = 0; j < 2; ++ j)
			matrix(i, j) = int(i == j);
	EXPECT_EQ (2, getNumberOfOnes());
}

TEST(bandmatr, minimumBandFor)
{
	matrix = Matrix<int>(2, 2);
	EXPECT_EQ(0, minimumBandFor(2));
	EXPECT_EQ(1, minimumBandFor(3));
	EXPECT_EQ(1, minimumBandFor(4));
	matrix = Matrix<int>(3, 3);
	EXPECT_EQ(1, minimumBandFor(4));
	EXPECT_EQ(1, minimumBandFor(7));
	EXPECT_EQ(2, minimumBandFor(8));
}
