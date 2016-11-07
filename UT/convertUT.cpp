#define CATCH_CONFIG_MAIN
#include "LIBS/catch/catch.hpp"
#include "../SRC/convert.hpp"

#include <string>
#include <vector>
#include <set>

std::queue<int> prepareQueue()
{
    std::vector<int> vector = {1,2,3,5,8};
    std::queue<int> queue;
    for(auto item : vector)
        queue.push(item);
    return queue;
}

void compareQueues(std::queue<int> expectedQueue, std::queue<int> outputQueue)
{
    REQUIRE(expectedQueue.size() == outputQueue.size());
    while(!expectedQueue.empty() and !outputQueue.empty())
    {
        REQUIRE(expectedQueue.front() == outputQueue.front());
        expectedQueue.pop();
        outputQueue.pop();
    }
}

TEST_CASE("should convert std::vector<int> to std::vector<int>", "[one dimensional]")
{
    std::vector<int> test_vector =  {1,2,3,5,8};
    REQUIRE(test_vector == convertTo<std::vector<int>>(test_vector));
}

TEST_CASE("should convert std::vector<std::string> to std::vector<std::string>", "[one dimensional]")
{
    std::vector<std::string> test_vector = { "Obi", "-", "wan", "Kenobi" };
    REQUIRE(test_vector == convertTo<std::vector<std::string>>(test_vector));
}

TEST_CASE("should convert std::vector<int> to std::set<int>", "[one dimensional]")
{
    std::vector<int> test_vector =  {1,2,3,5,8};
    std::set<int> test_set = {1,2,3,5,8};
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
    std::vector<int> input_vector = {1,2,3,5,8};
    std::queue<int> expected_queue = prepareQueue();
    auto output_queue = convertTo<std::queue<int>>(input_vector);
    compareQueues(output_queue, expected_queue);
}

TEST_CASE("should be able to convert from Queue", "[Queue]")
{
    std::queue<int> input_queue = prepareQueue();
    std::vector<int> expected_vector = {1,2,3,5,8};
    REQUIRE(expected_vector == convertTo<std::vector<int>>(input_queue));
}

TEST_CASE("should be able to convert Queue into Queue", "[Queue]")
{
    std::queue<int> input_queue = prepareQueue();
    std::queue<int> expected_queue = prepareQueue();
    auto output_queue = convertTo<std::queue<int>>(input_queue);
    compareQueues(output_queue, expected_queue);
}
