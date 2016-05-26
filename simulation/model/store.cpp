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
	for(Checkout q : checkouts_){
		q.Update(delta);
	}
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

vector<Checkout> Store::GetCheckoutsNearby(int position, int amount){
	vector<Checkout> result;
	int start = position - (amount/2);
	int end = start + amount;
	int max = checkouts_.size();
	for(int i = start; i < end; i++){
		if(i < 0 || i >= max){ continue; }
		result.push_back(checkouts_[i]);
	}
	return result;
}

