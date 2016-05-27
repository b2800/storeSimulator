#ifndef SIMULATION_PARAMETERS_
#define SIMULATION_PARAMETERS_

#include <string>

enum class Distribution{EXP, POISSON};

struct Data{
	Distribution distribution;
	int resolution;
	int total_duration;
	int checkout_count;
	float lambda; //parameter for wait between clients
	float mu;	//parameter for client processing time
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
