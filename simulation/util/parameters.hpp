#ifndef SIMULATION_PARAMETERS_
#define SIMULATION_PARAMETERS_

#include <string>

enum class Distribution{EXP, POISSON};
enum class Method{RANDOM, LESS, APPROXIMATION};

struct Data{
	Distribution distribution;
	int resolution;
	int total_duration;
	int checkout_count;
	float lambda; //parameter for wait between clients
	float mu;	//parameter for client processing time
	Method checkout_choosing_method;
	std::string output_file;
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
