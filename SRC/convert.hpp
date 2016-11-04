#pragma once

#include <algorithm>
#include <utility>
#include <iterator>

template <typename Container>
struct IsContainer
{
    typedef char yes[1];
    typedef char no[2];

    template <typename Class>
    static yes& check(decltype(&Class::size));

    template <typename>
    static no& check(...);

    static const bool isContainer = sizeof(check<Container>(0))==sizeof(yes);
};

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
