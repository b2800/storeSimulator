#ifndef SIMULATION_HPP_
#define SIMULATION_HPP_

class Simulation{
	public:
		Simulation();
		ProvideGenerator(Generator);
		Start();

	private:
		Store store_;
		Generator generator_;
};

#endif //SIMULATION_HPP_
