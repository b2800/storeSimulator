#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

#include "model/store.hpp"

class Simulation{
	public:
		Simulation();
		~Simulation();
		void Start();

	private:
		Store store_;
};

#endif //SIMULATION_HPP_
