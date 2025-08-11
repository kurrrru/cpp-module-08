#pragma once

#include <algorithm>

template <typename T>
typename T::const_iterator easyfind(const T &container,
        const typename T::value_type &value) {
    return std::find(container.begin(), container.end(), value);
}
