#include "client.hpp"

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

}
