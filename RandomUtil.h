#pragma once
#include <random>

namespace rul {
	template<class T>
	T rndm_int_ir(const T min, const T max) {
		std::random_device seed;
		std::mt19937 engine(seed());
		std::uniform_int_distribution<T> dist(min, max);
		return dist(engine);
	}

	template<class T>
	T rndm_int_ir(const T min, const T max, long long seed) {
		std::mt19937 engine(seed);
		std::uniform_int_distribution<T> dist(min, max);
		return dist(engine);
	}

	template<class T>
	T rndm_floatingpoint_ir(const T min, const T max) {
		std::random_device seed;
		static std::default_random_engine e(seed());
		static std::uniform_real_distribution<T> dis(min, max);
		return dis(e);
	}

	template<class T>
	T rndm_floatingpoint_ir(const T min, const T max, long long seed) {
		static std::default_random_engine e(seed);
		static std::uniform_real_distribution<T> dis(min, max);
		return dis(e);
	}
}