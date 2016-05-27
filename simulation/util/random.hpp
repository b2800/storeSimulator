#ifndef UTIL_RANDOM_HPP_
#define UTIL_RANDOM_HPP_

#include <random>
#include "parameters.hpp"

class Random{
	public:
		static void Initialize();
		static int NextVariableInt(float);
		static int NextUniformInt();
		static int GetClientProcessingTime();

	private:
		static std::default_random_engine generator_;
		static std::exponential_distribution<float> exp_distribution_;
		static std::poisson_distribution<int> poisson_distribution_;
		static std::uniform_int_distribution<int> uniform_distribution_;
		static Distribution dist_;
};

#endif //UTIL_RANDOM_HPP_
