#ifndef STORE_HPP_
#define STORE_HPP_

#include <vector>
#include "queue.hpp"

using namespace std;


class Store{
	public:
		Store();
		void Update(float);
		std::vector<QueueState> GetState();

	private:
		vector<Queue> queues_;
};

#endif STORE_HPP_
