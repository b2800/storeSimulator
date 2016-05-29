#include "store.hpp"
#include "../util/parameters.hpp"
#include "../util/random.hpp"
#include <iostream>

using namespace std;

Store::Store(){
	timer_ = 0;
}

void Store::Initialize(){
	int checkout_count = Parameters::Get().checkout_count;
	for(int i = 0; i < checkout_count; i++){
		CreateCheckout();
	}
}

void Store::Update(float delta){
	UpdateTimer(delta);
	int i = 0;
	for(Checkout q : checkouts_){
		std::cout << "Updated checkout " << i << std::endl;
		q.Update(delta);
		i++;
	}
}

void Store::UpdateTimer(float delta){
	timer_ -= delta;

	while(timer_ <= 0){
		SendNewClientToCheckouts();
		float new_timer = Random::NextVariableFloat(Parameters::Get().lambda);
		timer_ += new_timer; // Take in account case when timer is smaller than simulation resolution
	}
}

void Store::SendNewClientToCheckouts(){
	int pos = Random::NextUniformInt(Parameters::Get().checkout_count);
	float theta_s = Random::NextVariableFloat(Parameters::Get().mu);
	std::cout << "new client theta_s " << theta_s << std::endl;
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

