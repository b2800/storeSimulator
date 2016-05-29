#ifndef CHECKOUT_HPP_
#define CHECKOUT_HPP_

#include <vector>
#include "client.hpp"

using namespace std;

struct CheckoutState{
	bool open;
	int current_client_count;
	int total_unhappy_clients;
	int total_clients;
	float average_speed;
	float maximum_speed;
	vector<Client> clients;
};

class Checkout{
	public:
		Checkout();
		void Update(float);
		void AddClient(Client);
		CheckoutState GetState();

	private:
		float timer_;
		Client* current_client;
		vector<Client> clients_;
};

#endif
