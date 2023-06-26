#pragma once
#include <chrono>

template<class T>
class Clock final {
public:
	std::chrono::high_resolution_clock::time_point start;

	Clock() {
		reset();
	}

	inline void reset() {
		start = std::chrono::high_resolution_clock::now();
	}

	inline bool has_time_elapsed(const T time) {
		return std::chrono::duration_cast<T>(std::chrono::high_resolution_clock::now() - start) >= time;
	}

	inline long long start_count() {
		return start.time_since_epoch().count();
	}
};