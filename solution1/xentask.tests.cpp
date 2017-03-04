#include "xentask.hpp"
#include <gtest/gtest.h>

using namespace ::testing;

TEST(xentask, DISABLED_read)
{
	EXPECT_NO_THROW(readData());
}
TEST(xentask, alternate)
{
	numberOfTasks = 3;
	taskDurations[0] = std::vector<int>{1,2,3};
	taskDurations[1] = std::vector<int>{0,2,3};
	EXPECT_EQ(6, alternateStartingFrom(0));
}
