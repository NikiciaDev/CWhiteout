#pragma once
#include <random>

namespace random {
	static std::random_device rndm;
	static std::mt19937 base_engine(rndm());

	template<class T>
	T intg(const T min, const T max) {
		std::uniform_int_distribution<T> dist(min, max);
		return dist(base_engine);
	}

	template<class T>
	T intg(const T min, const T max, long long seed) {
		std::mt19937 engine(seed);
		std::uniform_int_distribution<T> dist(min, max);
		return dist(engine);
	}

	template<class T>
	T fltp(const T min, const T max) {
		static std::uniform_real_distribution<T> dis(min, max);
		return dis(base_engine);
	}

	template<class T>
	T fltp(const T min, const T max, long long seed) {
		static std::default_random_engine engine(seed);
		static std::uniform_real_distribution<T> dist(min, max);
		return dist(engine);
	}
}