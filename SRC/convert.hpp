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
    {
        outContainer.push(item);
    }
    return outContainer;
}
