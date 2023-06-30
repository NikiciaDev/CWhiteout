#pragma once
#include <random>

class Random {
public:
	std::random_device rndm;
	std::mt19937 base_engine;

	Random() {
		base_engine = std::mt19937(rndm());
	}

	template<class T>
	T intg(const T min, const T max) {
		std::uniform_int_distribution<T> dist(min, max);
		return dist(base_engine);
	}

	// Deprecated due to security risks.
	//template<class T>  // This funciton should be used carefully since everytime the radnom engine is reseeded the first few numbers arent as random.
	//T intg(const T min, const T max, long long seed) {
	//	std::mt19937 engine(seed);
	//	std::uniform_int_distribution<T> dist(min, max);
	//	return dist(engine);
	//}

	template<class T>
	T fltp(const T min, const T max) {
		std::uniform_real_distribution<T> dis(min, max);
		return dis(base_engine);
	}

	// Deprecated due to security risks.
	//template<class T> // This funciton should be used carefully since everytime the radnom engine is reseeded the first few numbers arent as random.
	//T fltp(const T min, const T max, long long seed) {
	//	std::default_random_engine engine(seed);
	//	std::uniform_real_distribution<T> dist(min, max);
	//	return dist(engine);
	//}
};

template<class T>
class RandomVar {
private:
	bool initialized { false };
	T value;

public:
	RandomVar() { }

	RandomVar(const T default_value) : value(default_value), initialized(true) { }

	bool ii() {
		return this->initialized;
	}

	void sv(const T value) {
		this->value = value;
		initialized = true;
	}

	T gv() {
		return this->value;
	}
};