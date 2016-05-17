
Simulation::Simulation(){
	
}

void Simulation::Start(int steps){

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