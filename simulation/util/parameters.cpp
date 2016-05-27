#include "parameters.hpp"

using namespace std;

void Parameters::Parse(int argc, char** argv){
	if(argc == 1){	// Default parameters
		LoadDefault();
		return;
	}
	LoadDefault(); //remplace this with proper parsing
}

void Parameters::LoadDefault(){
	data_.distribution = Distribution::EXP;
	data_.resolution = 2;
	data_.total_duration = 120;
	data_.checkout_count = 5;
	data_.output_file = "results.json";
	data_.lambda = 4;
	data_.mu = 10;
}

Data Parameters::Get(){
	return data_;
}

Data Parameters::data_;
