#ifndef QUEUE_HPP_
#define QUEUE_HPP_

#include <vector>
#include "client.hpp"

using namespace std;

struct QueueState{
	int current_client_count;
	int total_unhappy_clients;
	int total_clients;
};

class Queue{
	public:
		Queue();
		void Update(float);
		QueueState GetState();

	private:
		QueueState state_;
		vector<Client> clients_;
};

#endif
