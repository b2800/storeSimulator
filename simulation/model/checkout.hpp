#ifndef CHECKOUT_HPP_
#define CHECKOUT_HPP_

#include <deque>
#include "client.hpp"

using namespace std;

struct CheckoutState{
	int current_client_count;
	int total_unhappy_clients;
	int total_clients;
};

class Checkout{
	public:
		Checkout();
		void Update(float);
		CheckoutState GetState();

	private:
		CheckoutState state_;
		deque<Client> clients_;
};

#endif
