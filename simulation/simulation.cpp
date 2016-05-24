#include "simulation.hpp"

Simulation::Simulation(){

}

Simulation::~Simulation(){
	delete generator_;
}

void Simulation::Start(int steps, int resolution){

	while(steps != 0){
		Time::Advance();
		store.Update(Time::GetDelta());
		Network::Send(store.GetState);
		steps--;
	}
}

int main(int argc, char** args){
	Simulation s;
	s.Start(100);
}
