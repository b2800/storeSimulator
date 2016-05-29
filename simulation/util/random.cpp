#include "random.hpp"
#include "parameters.hpp"
#include <ctime>
#include <iostream>

void Random::Initialize(){
	Data params = Parameters::Get();
	dist_ = params.distribution;
	generator_.seed(time(NULL));
}

float Random::NextVariableFloat(float param){
	std::exponential_distribution<float> exp(param);
	std::poisson_distribution<int> poisson(param);
	switch(dist_){
		case Distribution::POISSON:
			return poisson(generator_);
		case Distribution::EXP:
		default:
			return exp(generator_)*10;
	}
}

int Random::NextUniformInt(int param){
	std::uniform_int_distribution<int> dist = std::uniform_int_distribution<int>(0, param);
	return dist(generator_);
}


std::default_random_engine Random::generator_(time(NULL));
Distribution Random::dist_;
