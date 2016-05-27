#include "random.hpp"
#include "parameters.hpp"

void Random::Initialize(){
	Data params = Parameters::Get();
	dist_ = params.distribution;
	uniform_distribution_ = std::uniform_int_distribution<int>(params.checkout_count);
}

int Random::NextVariableInt(float param){
	std::exponential_distribution<float> exp(param);
	std::poisson_distribution<int> poisson(param);
	switch(dist_){
		case Distribution::POISSON:
			return poisson(generator_);
		case Distribution::EXP:
		default:
			return exp(generator_);
	}
}

int Random::NextUniformInt(){
	return uniform_distribution_(generator_);
}


std::default_random_engine Random::generator_;
std::uniform_int_distribution<int> Random::uniform_distribution_;
Distribution Random::dist_;
