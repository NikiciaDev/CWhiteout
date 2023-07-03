#pragma once
#include <cmath>

namespace math {
	template<class T>
    T round_to_increment(T value, T increment) {
        T flooredValue = std::floor(value / increment) * increment;
        T difference = value - flooredValue;
        if (difference >= increment / T(2.0)) {
            return flooredValue + increment;
        } else {
            return flooredValue;
        }
    }
}