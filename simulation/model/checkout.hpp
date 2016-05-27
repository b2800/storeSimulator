#ifndef CHECKOUT_HPP_
#define CHECKOUT_HPP_

#include <deque>
#include "client.hpp"

using namespace std;

struct CheckoutState{
	bool open;
	int current_client_count;
	int total_unhappy_clients;
	int total_clients;
	float average_speed;
	float maximum_speed;
	deque<Client> clients;
};

class Checkout{
	public:
		Checkout();
		void Update(float);
		void AddClient(Client);
		CheckoutState GetState();

	private:
		CheckoutState state_;
		float timer_;
		Client* current_client;
};

#endif
