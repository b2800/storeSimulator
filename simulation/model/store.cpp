#include "store.hpp"

using namespace std;

Store::Store(){

}

void Store::Update(float delta){
	for(Queue q : queues_){
		q.Update(delta);
	}
}

vector<QueueState> Store::GetState(){
	vector<QueueState> full_state;
	for(Queue q : queues_){
		full_state.push_back(q.GetState());
	}
	return full_state;
}

