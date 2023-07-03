#pragma once
#include <vector>

namespace vmu {
	template<class T>
	unsigned short next(const std::vector<T>& vector, const unsigned short pos, const bool down) {
		if (down) {
			if (pos <= 0) return vector.size() - 1;
			return pos - 1;
		}
		if (pos >= vector.size() - 1) return 0;
		return pos + 1;
	}
}