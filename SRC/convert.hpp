#pragma once

#include "container.hpp"

#include <algorithm>
#include <utility>
#include <iterator>
#include <queue>


template<typename Out, typename In>
auto convertTo(const In& in)
    -> typename std::enable_if<!IsContainer<In>::isContainer,
                               Out>::type
{
    Out outContainer;
    outContainer.insert(std::end(outContainer), in);
    return outContainer;
}

template<typename Out, typename In>
auto convertTo(const In& inContainer)
    -> typename std::enable_if<IsContainer<In>::isContainer
                               && !std::is_same<In, std::queue<typename In::value_type> >::value
                               && !std::is_same<Out, std::queue<typename Out::value_type> >::value,
                               Out>::type
{
    Out outContainer;
    std::copy(std::begin(inContainer),
              std::end(inContainer),
              std::inserter(outContainer, outContainer.end()));

    return outContainer;
}

template<typename Out, typename In>
auto convertTo(const In& in)
    -> typename std::enable_if<IsContainer<In>::isContainer
                               && std::is_same<Out, std::queue<typename Out::value_type> >::value,
                               Out>::type
{
    Out outContainer;
    for(auto item : in)
        outContainer.push(item);
    return outContainer;
}

template<typename Out, typename TypeInQueue>
auto convertTo(const std::queue<TypeInQueue>& in)
    -> typename std::enable_if<!IsContainer<TypeInQueue>::isContainer
                               && !std::is_same<Out, std::queue<typename Out::value_type> >::value,
                               Out>::type
{
    Out outContainer;
    std::queue<TypeInQueue> tmp_queue = in;
    while(!tmp_queue.empty())
    {
        outContainer.insert(std::end(outContainer),
                            tmp_queue.front());
        tmp_queue.pop();
    }
    return outContainer;
}

template <typename Out, typename TypeInQueue>
auto convertTo(const std::queue<TypeInQueue>& in)
    -> typename std::enable_if<!IsContainer<TypeInQueue>::isContainer
                               && std::is_same<Out, std::queue<typename Out::value_type> >::value,
                               Out>::type
{
    Out outContainer;
    std::queue<TypeInQueue> tmp_queue = in;
    while(!tmp_queue.empty())
    {
        outContainer.push(tmp_queue.front());
        tmp_queue.pop();
    }
    return outContainer;
}
