#include "client.hpp"
#include "../util/parameters.hpp"
#include "../util/random.hpp"
#include "checkout.hpp"
#include <iostream>

Client::Client(float theta_s, int position){
	theta_s_ = theta_s;
	position_ = position;
	mood_ = Mood::NEUTRAL;
}

Mood Client::GetMood(){
	return mood_;
}

float Client::GetThetaS(){
	return theta_s_;
}

void Client::PickCheckout(vector<Checkout*> available_checkouts){
	if(available_checkouts.empty()){ return; }

	Checkout* choosen_checkout = nullptr;
	switch(Parameters::Get().checkout_choosing_method){
		case Method::LESS:
			choosen_checkout = GetLessFull(available_checkouts);
			break;
		case Method::APPROXIMATION:
			choosen_checkout = GetByThetaSApproximation(available_checkouts);
			break;
		case Method::RANDOM:
		default:
			choosen_checkout = GetRandom(available_checkouts);
	}

	// Mood modifier
	int size = choosen_checkout->GetState().clients.size();
	if(size == 0){	// Default to happy when client don't have to wait;
		mood_ = Mood::HAPPY;
	} else if (size >= 5){
		mood_ = Mood::UNHAPPY;
	}

	choosen_checkout->AddClient(*this);
}

Checkout* Client::GetRandom(vector<Checkout*> available_checkouts){
	int random = Random::NextUniformInt(available_checkouts.size()-1);
	return available_checkouts[random];
}

Checkout* Client::GetLessFull(vector<Checkout*> available_checkouts){
	int size = available_checkouts[0]->GetState().clients.size();
	int id = 0;

	for(unsigned int i = 1; i < available_checkouts.size(); i++){
		int current_size = available_checkouts[i]->GetState().clients.size();
		if(current_size < size){
			size = current_size;
			id = i;
		}
	}
	return available_checkouts[id];
}

Checkout* Client::GetByThetaSApproximation(vector<Checkout*> available_checkouts){
	return GetLessFull(available_checkouts); //TODO : Change this
}
