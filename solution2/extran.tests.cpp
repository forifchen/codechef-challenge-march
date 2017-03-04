#include "extran.hpp"
#include <gtest/gtest.h>

TEST(DISABLED_extran, reading)
{
	EXPECT_NO_THROW(readSequence());
}

TEST(extran, findExcludable)
{
	sequence = {1, 2, 5};
	EXPECT_EQ(5, findExcludable());

	sequence = {1, 4, 5};
	EXPECT_EQ(1, findExcludable());

	sequence = {1, 2, 2};
	EXPECT_EQ(2, findExcludable());

	sequence = {1, 2, 3};
	EXPECT_EQ(-1, findExcludable());
}
