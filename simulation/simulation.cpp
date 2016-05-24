#include "simulation.hpp"
#include "util/time.hpp"
#include "util/file.hpp"

#include "generator/exp.hpp"
#include "generator/poisson.hpp"

#include <string>

Simulation::Simulation(){
	string gen = Parameters::Get("Generator");
	if(gen == "exp"){
		generator_ = new ExponentialGenerator();
	} else if (gen == "poisson"){
		generator_ = new PoissonGenerator();
	}
}

Simulation::~Simulation(){
	delete generator_;
}

void Simulation::Start();

	while(steps != 0){
		Time::Advance();
		store_.Update(Time::GetDelta());
		File::Save(store_.GetState());
		steps--;
	}
	File::Flush();
}

int main(int argc, char** args){
	Parameters::Parse(argc, args);
	Time::Initialize();
	File::Initialize();

	Simulation s;
	s.Start();
}
