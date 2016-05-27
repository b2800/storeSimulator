#include "store.hpp"
#include "../util/parameters.hpp"
#include "../util/random.hpp"
#include <iostream>

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
	UpdateTimer(delta);
	for(Checkout q : checkouts_){
		q.Update(delta);
	}
}

void Store::UpdateTimer(float delta){
	timer_ -= delta;
	if(timer_ > 0){ return; }

	SendNewClientToCheckouts();
	int new_timer = Random::NextVariableInt(Parameters::Get().lambda);
	timer_ += new_timer; // Take in account case when timer is smaller than simulation resolution
}

void Store::SendNewClientToCheckouts(){
	int pos = Random::NextUniformInt();
	int theta_s = Random::NextVariableInt(Parameters::Get().mu);
	Client c(pos, theta_s);
	c.PickCheckout(GetCheckoutsNearby(pos, 3));
}

void Store::CreateCheckout(){
	Checkout c;
	checkouts_.push_back(c);
}

vector<CheckoutState> Store::GetState(){
	vector<CheckoutState> full_state;
	for(Checkout q : checkouts_){
		full_state.push_back(q.GetState());
	}
	return full_state;
}

vector<Checkout*> Store::GetCheckoutsNearby(int position, int amount){
	vector<Checkout*> result;
	int start = position - (amount/2);
	int end = start + amount;
	int max = checkouts_.size();
	for(int i = start; i < end; i++){
		if(i < 0 || i >= max){ continue; }
		result.push_back(&(checkouts_[i]));
	}
	return result;
}

