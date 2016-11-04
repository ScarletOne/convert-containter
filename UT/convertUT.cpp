#define CATCH_CONFIG_MAIN
#include "LIBS/catch/catch.hpp"
#include "../SRC/convert.hpp"
#include <vector>

unsigned int dummyFunc()
{
    return 1;
}

TEST_CASE("just a dummy passing test", "[dummy]")
{
    REQUIRE(dummyFunc() == 1);
}

TEST_CASE("convert vector to vector", "[vector]")
{
    std::vector<int> v1 = {1,2,3};
    REQUIRE(v1 == convert(v1));
}
