#pragma once

#include "container.hpp"

#include <algorithm>
#include <utility>
#include <iterator>


template<typename Out, typename In>
auto convert(const In& in)
    -> typename std::enable_if<!IsContainer<In>::isContainer,
                                Out>::type
{
    Out outContainer;
    outContainer.insert(std::end(outContainer), in);
    return outContainer;
}

template<typename Out, typename In>
auto convert(const In& inContainer)
    -> typename std::enable_if<IsContainer<In>::isContainer,
                               Out>::type
{
    Out outContainer;
    for(auto item : inContainer)
    {
        outContainer.insert(std::end(outContainer), item);
    }

    return outContainer;
}
