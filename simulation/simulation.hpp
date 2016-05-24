#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include "generator/generator.hpp"
#include "model/store.hpp"

class Simulation{
	public:
		Simulation();
		~Simulation();
		void Start();

	private:
		Store store_;
		Generator* generator_;
};

#endif //SIMULATION_HPP_
