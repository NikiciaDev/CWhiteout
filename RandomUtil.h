#pragma once
#include <random>

namespace rul {
	template<class T>
	T rndm_num_ir(const T min, const T max) {
		std::random_device seed;
		std::mt19937 engine(seed());
		std::uniform_int_distribution<T> dist(min, max);
		return dist(engine);
	}

	template<class T>
	T rndm_num_ir(const T min, const T max, long long seed) {
		std::mt19937 engine(seed);
		std::uniform_int_distribution<T> dist(min, max);
		return dist(engine);
	}
}