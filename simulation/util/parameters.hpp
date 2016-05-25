#ifndef SIMULATION_PARAMETERS_
#define SIMULATION_PARAMETERS_

enum class Model{EXP, POISSON};

struct Data{
	Model model;
	int steps;
	int resolution;
};

class Parameters{
	public:
		static void Parse(int, char**);
		static Data Get();

	private:
		static Data data_;
};

#endif
