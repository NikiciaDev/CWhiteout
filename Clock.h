#pragma once
#include <chrono>

template<class T>
class Clock final {
public:
	T last;

	inline Clock() {
		last = get_current_time();
	}

	inline T get_current_time() {
		auto now = std::chrono::system_clock::now();
		T milliseconds = std::chrono::duration_cast<T>(now.time_since_epoch());
		return milliseconds;
	}

	inline void reset() {
		last = get_current_time();
	}

	inline bool has_time_elapsed(T time) {
		return (last + time) <= get_current_time();
	}
};