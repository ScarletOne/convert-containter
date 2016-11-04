#define CATCH_CONFIG_MAIN
#include "LIBS/catch/catch.hpp"
#include "../SRC/convert.hpp"

#include <string>
#include <vector>

TEST_CASE("convert vector<int> to vector<int>", "[one dimensional]")
{
    std::vector<int> v1 = {1,2,3};
    REQUIRE(v1 == convert(v1));
}

TEST_CASE("convert vector<std::string> to vector<std::string>", "[one dimensional]")
{
    std::vector<std::string> v1 = { "Obi", "-", "wan", "Kenobi"};
    REQUIRE(v1 == convert(v1));
}
