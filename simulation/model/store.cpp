#include "store.hpp"
#include "../util/parameters.hpp"

using namespace std;

Store::Store(){

}

void Store::Initialize(){
	int checkout_count = Parameters::Get().checkout_count;
	for(int i = 0; i < checkout_count; i++){
		CreateCheckout();
	}
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

vector<Queue> Store::GetQueuesNearby(int position, int amount){
	vector<Queue> result;
	int start = position - (amount/2);
	int end = start + amount;
	int max = queues_.size();
	for(int i = start; i < end; i++){
		if(i < 0 || i >= max){ continue; }
		result.push_back(queues_[i]);
	}
	return result;
}

