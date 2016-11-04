#pragma once

#include "container.hpp"

#include <algorithm>
#include <utility>
#include <iterator>


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
    -> typename std::enable_if<IsContainer<In>::isContainer,
                               Out>::type
{
    Out outContainer;
    std::copy(std::begin(inContainer),
              std::end(inContainer),
              std::inserter(outContainer, outContainer.end()));

    return outContainer;
}
