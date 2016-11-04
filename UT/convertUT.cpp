#define CATCH_CONFIG_MAIN
#include "LIBS/catch/catch.hpp"
#include "../SRC/convert.hpp"
#include <vector>

TEST_CASE("convert vector to vector", "[one dimensional]")
{
    std::vector<int> v1 = {1,2,3};
    REQUIRE(v1 == convert(v1));
}
