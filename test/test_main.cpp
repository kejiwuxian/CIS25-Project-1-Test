#include "gtest/gtest.h"
#include "util/convert_currency.hpp"
#include "util/convert_unit.hpp"
#include "util/strip_and_to_lower.hpp"
#include "util/process_input_original.hpp"
#include "util/process_input_target.hpp"

TEST(units, convert_unit)
{
	EXPECT_EQ(units::convert_unit(1, units::kg, units::g), 1000);
	EXPECT_EQ(units::convert_unit(1, units::kg, units::jin), 2);
}

TEST(util, strip_and_to_lower)
{
	std::string str = " Hello World! ";
	util::strip_and_to_lower(str);
	EXPECT_EQ(str, "hello world!");
	str = "kahf AOLH KJXKZ ";
	util::strip_and_to_lower(str);
	EXPECT_EQ(str, "kahf aolh kjxkz");
}

TEST(user_interaction, process_input_original)
{
	currencies::currencies currency;
	units::units unit;
	double price, weight;
	user_interaction::process_input("4.99usd/lb", price, currency, weight, unit);
	EXPECT_EQ(price, 4.99);
	EXPECT_EQ(currency, currencies::usd);
	EXPECT_EQ(weight, 1);
	EXPECT_EQ(unit, units::lb);
	user_interaction::process_input("4.99uSd/1lb", price, currency, weight, unit);
	EXPECT_EQ(price, 4.99);
	EXPECT_EQ(currency, currencies::usd);
	EXPECT_EQ(weight, 1);
	EXPECT_EQ(unit, units::lb);
	user_interaction::process_input("4.99usd/1.0lB", price, currency, weight, unit);
	EXPECT_EQ(price, 4.99);
	EXPECT_EQ(currency, currencies::usd);
	EXPECT_EQ(weight, 1);
	EXPECT_EQ(unit, units::lb);
}

TEST(user_interaction, process_input_target)
{
	currencies::currencies currency;
	units::units unit;
	user_interaction::process_input("usd/lb", currency, unit);
	EXPECT_EQ(currency, currencies::usd);
	EXPECT_EQ(unit, units::lb);
	user_interaction::process_input("cny/kg", currency, unit);
	EXPECT_EQ(currency, currencies::cny);
	EXPECT_EQ(unit, units::kg);
}

int main(int argc, char** argv)
{
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}