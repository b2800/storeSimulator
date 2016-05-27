#include "simulation.hpp"
#include "util/parameters.hpp"
#include "util/time.hpp"
#include "util/file.hpp"

#include <string>

Simulation::Simulation(){
}

Simulation::~Simulation(){

}

void Simulation::Start(){
	store_.Initialize();

	Data data = Parameters::Get();
	int steps = data.total_duration / data.resolution;
	while(steps > 0){
		Time::Advance();
		store_.Update(Time::GetDelta());
		File::Save(store_.GetState(), Time::GetCurrentTime());
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
