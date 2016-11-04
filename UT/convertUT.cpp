#define CATCH_CONFIG_MAIN
#include "LIBS/catch/catch.hpp"
#include "../SRC/convert.hpp"

#include <string>
#include <vector>
#include <set>

TEST_CASE("should convert std::vector<int> to std::vector<int>", "[one dimensional]")
{
    std::vector<int> test_vector = { 1,2,3 };
    REQUIRE(test_vector == convertTo<std::vector<int>>(test_vector));
}

TEST_CASE("should convert std::vector<std::string> to std::vector<std::string>", "[one dimensional]")
{
    std::vector<std::string> test_vector = { "Obi", "-", "wan", "Kenobi" };
    REQUIRE(test_vector == convertTo<std::vector<std::string>>(test_vector));
}

TEST_CASE("should convert std::vector<int> to std::set<int>", "[one dimensional]")
{
    std::vector<int> test_vector = { 1,2,3 };
    std::set<int> test_set = { 1,2,3 };
    REQUIRE(test_set == convertTo<std::set<int>>(test_vector));
}

TEST_CASE("should convert int to vector<int>", "[base type deduction]")
{
    std::vector<int> required_output = { 1 };
    int input = 1;
    REQUIRE(required_output == convertTo<std::vector<int>>(input));
}
