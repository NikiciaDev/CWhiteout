#pragma once
#include <chrono>

template<class T>
class Clock final {
public:
	std::chrono::high_resolution_clock::time_point start;

	Clock() {
		reset();
	}

	static inline std::string get_time() {
		time_t currentTime = time(nullptr);
		struct tm localTime;
		localtime_s(&localTime, &currentTime);

		char timeBuffer[80];
		strftime(timeBuffer, sizeof(timeBuffer), "%Y-%m-%d %H:%M:%S", &localTime);

		return std::string(timeBuffer);
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