#ifndef SIMULATION_PARAMETERS_
#define SIMULATION_PARAMETERS_

enum class Model{EXP, POISSON};

struct Data{
	Model model;
	int steps;
	int resolution;
	int checkout_count;
};

class Parameters{
	public:
		static void LoadDefault();
		static void Parse(int, char**);
		static Data Get();

	private:
		static Data data_;
};

#endif
