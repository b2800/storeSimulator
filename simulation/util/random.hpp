#ifndef UTIL_RANDOM_HPP_
#define UTIL_RANDOM_HPP_

#include <random>
#include "parameters.hpp"

class Random{
	public:
		static void Initialize();
		static float NextVariableFloat(float);
		static int NextUniformInt(int);
		static int GetClientProcessingTime();

	private:
		static std::default_random_engine generator_;
		static Distribution dist_;
};

#endif //UTIL_RANDOM_HPP_
