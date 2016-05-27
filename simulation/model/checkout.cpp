#include <iostream>
#include "checkout.hpp"

using namespace std;

Checkout::Checkout(){
	timer_ = 0;
	current_client = nullptr;
}

void Checkout::Update(float delta){
	if(!current_client){
		if(state_.clients.size() == 0){ return; }
		current_client = &(state_.clients.front());
	}

	timer_ -= delta;
	if(timer_ > 0){ return; }

	current_client = nullptr;
	state_.clients.pop_front();
}

void Checkout::AddClient(Client c){
	state_.clients.push_back(c);
}

CheckoutState Checkout::GetState(){
	return state_;
}

