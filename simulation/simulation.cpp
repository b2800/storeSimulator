#include "simulation.hpp"
#include "util/parameters.hpp"
#include "util/time.hpp"
#include "util/file.hpp"

#include "generator/exp.hpp"
#include "generator/poisson.hpp"

#include <string>

Simulation::Simulation(){
	switch(Parameters::Get().model){
		case Model::POISSON:
			generator_ = new PoissonModel();
			break;

		case Model::EXP:
		default:
			generator_ = new ExponentialModel();
	}
}

Simulation::~Simulation(){
	delete generator_;
}

void Simulation::Start(){
	store.Initialize();
	int steps = Parameters::Get().steps;

	while(steps != 0){
		Time::Advance();
		store_.Update(Time::GetDelta());
		File::Save(store_.GetState());
		steps--;
	}
}

int main(int argc, char** args){
	Parameters::Parse(argc, args);
	Time::Initialize();
	File::Initialize();

	Simulation s;
	s.Start();
}
