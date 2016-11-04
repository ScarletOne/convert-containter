#pragma once

#include "container.hpp"

#include <algorithm>
#include <utility>
#include <iterator>


template<typename Out, typename In>
typename std::enable_if<!IsContainer<In>::isContainer, Out>::type
convert(const In& in)
{
    Out outContainer;
    outContainer.insert(std::end(outContainer), in);
    return outContainer;
}

template<typename Out, typename In>
typename std::enable_if<IsContainer<In>::isContainer, Out>::type
convert(const In& inContainer)
{
    Out outContainer;
    for(auto item : inContainer)
    {
        outContainer.insert(std::end(outContainer), item);
    }

    return outContainer;
}
