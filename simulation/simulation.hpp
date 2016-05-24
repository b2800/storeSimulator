#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include "generator/generator.hpp"

class Simulation{
	public:
		Simulation();
		~Simulation();
		void ProvideGenerator(Generator*);
		void Start(int, int);

	private:
		Store store_;
		Generator* generator_;
};

#endif //SIMULATION_HPP_
