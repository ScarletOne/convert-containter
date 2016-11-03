#define CATCH_CONFIG_MAIN
#include "LIBS/catch/catch.hpp"


unsigned int dummyFunc()
{
    return 1;
}

TEST_CASE("just a dummy passing test", "[dummy]")
{
    REQUIRE(dummyFunc() == 1);
}
