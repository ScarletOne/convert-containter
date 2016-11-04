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

TEST_CASE("should be able to convert to Queue", "[Queue]")
{
    std::vector<int> input_vector = { 1 };
    std::queue<int> expected_queue;
    expected_queue.push(1);
    auto output_queue = convertTo<std::queue<int>>(input_vector);
    REQUIRE(output_queue.size() == expected_queue.size());
    REQUIRE(output_queue.front() == expected_queue.front());
}

TEST_CASE("should be able to convert from Queue", "[Queue]")
{
    std::queue<int> input_queue;
    input_queue.push(1);
    std::vector<int> expected_vector = { 1 };
    REQUIRE(expected_vector == convertTo<std::vector<int>>(input_queue));
}
