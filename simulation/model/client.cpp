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
	switch(Parameters::Get().checkout_choosing_method){
		case Method::LESS:
			ChooseLessFull(available_checkouts);
			break;
		case Method::APPROXIMATION:
			ChooseFromThetaSApproximation(available_checkouts);
			break;
		case Method::RANDOM:
		default:
			ChooseRandomly(available_checkouts);
	}
}

void Client::ChooseRandomly(vector<Checkout*> available_checkouts){
	int random = Random::NextUniformInt(available_checkouts.size()-1);
	available_checkouts[random]->AddClient(*this);
}

void Client::ChooseLessFull(vector<Checkout*> available_checkouts){
	if(available_checkouts.empty()){ return; }
	int size = available_checkouts[0]->GetState().clients.size();
	int id = 0;

	for(unsigned int i = 1; i < available_checkouts.size(); i++){
		int current_size = available_checkouts[i]->GetState().clients.size();
		if(current_size < size){
			size = current_size;
			id = i;
		}
	}
	available_checkouts[id]->AddClient(*this);
}

void Client::ChooseFromThetaSApproximation(vector<Checkout*> available_checkouts){
	ChooseLessFull(available_checkouts); //TODO : Change this
}
