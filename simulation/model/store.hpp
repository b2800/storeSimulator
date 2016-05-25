#ifndef STORE_HPP_
#define STORE_HPP_

#include <vector>
#include "queue.hpp"

using namespace std;


class Store{
	public:
		Store();
		void Initialize();
		void Update(float);
		vector<Queue> GetQueuesNearby(int, int);
		std::vector<QueueState> GetState();

	private:
		void CreateCheckout();
		vector<Queue> queues_;
};

#endif STORE_HPP_
