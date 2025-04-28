#include "gtest/gtest.h"
#include "util/convert_currency.hpp"
#include "util/convert_unit.hpp"

TEST(Convert, unit)
{
	EXPECT_EQ(units::convert_unit(1, units::kg, units::g), 1000);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}