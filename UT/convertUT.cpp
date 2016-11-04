#define CATCH_CONFIG_MAIN
#include "LIBS/catch/catch.hpp"
#include "../SRC/convert.hpp"

#include <string>
#include <vector>
#include <set>

TEST_CASE("convert std::vector<int> to std::vector<int>", "[one dimensional]")
{
    std::vector<int> test_vector = { 1,2,3 };
    REQUIRE(test_vector == convert<std::vector<int>>(test_vector));
}

TEST_CASE("convert std::vector<std::string> to std::vector<std::string>", "[one dimensional]")
{
    std::vector<std::string> test_vector = { "Obi", "-", "wan", "Kenobi" };
    REQUIRE(test_vector == convert<std::vector<std::string>>(test_vector));
}

TEST_CASE("convert std::vector<int> to std::set<int>", "[one dimensional]")
{
    std::vector<int> test_vector = { 1,2,3 };
    std::set<int> test_set = { 1,2,3 };
    REQUIRE(test_set == convert<std::set<int>>(test_vector));
}
