#include "Random.h"

std::random_device Random::rndm;
std::mt19937 Random::base_engine(rndm());