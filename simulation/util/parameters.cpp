#include "parameters.hpp"

using namespace std;

void Parameters::Parse(int argc, char** argv){
	if(argc == 1){	// Default parameters
		LoadDefault();
		return;
	}

}

void Parameters::LoadDefault(){
	data_.model = Model::EXP;
	data_.resolution = 10;
	data_.steps = 144;
	data_.checkout_count = 5;
}

Data Parameters::Get(){
	return data_;
}

Data Parameters::data_;
