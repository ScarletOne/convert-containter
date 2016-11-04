#pragma once

#include <algorithm>

template<typename OutContainer, typename InContainer>
OutContainer convert(const InContainer& inContainer)
{
    OutContainer outContainer;
    for(item : inContainer)
    {
        outContainer.insert(std::end(outContainer), item);
    }

    return outContainer;
}
