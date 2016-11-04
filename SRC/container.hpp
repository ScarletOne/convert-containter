#pragma once

#include <queue>

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
