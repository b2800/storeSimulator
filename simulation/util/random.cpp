#include "random.hpp"
#include "parameters.hpp"

void Random::Initialize(){
	Data params = Parameters::Get();
	dist_ = params.distribution;
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

int Random::NextUniformInt(int param){
	std::uniform_int_distribution<int> dist = std::uniform_int_distribution<int>(0, param);
	return dist(generator_);
}


std::default_random_engine Random::generator_;
Distribution Random::dist_;
