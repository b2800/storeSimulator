#include <iostream>
#include "checkout.hpp"

using namespace std;

Checkout::Checkout(){
	timer_ = 0;
	current_client = nullptr;
}

void Checkout::Update(float delta){
	std::cout << "begin update, client count " << clients_.size() << std::endl;;
	if(!current_client){
		if(clients_.empty()){ return; }
		current_client = &(clients_.front());
	}

	timer_ -= delta;
	while(timer_ <= 0){
		current_client = nullptr;
		clients_.erase( clients_.begin() );
		std::cout << "popping client, new size : " << clients_.size() << std::endl;
		if(clients_.empty()){
			timer_ = 0;
			current_client = nullptr;
			return;
		} else {
			current_client = &(clients_.front());
			timer_ += current_client->GetThetaS();
		}
	}

	std::cout << "update end, client count : " << clients_.size() << std::endl;
}

void Checkout::AddClient(Client c){
	std::cout << "new client added " << std::endl;
	clients_.push_back(c);
}

CheckoutState Checkout::GetState(){
	CheckoutState s;

	s.clients = clients_;
	s.open = true;
	s.total_clients = clients_.size();
	return s;
}

