#ifndef STORE_HPP_
#define STORE_HPP_

#include <vector>
#include "checkout.hpp"

using namespace std;

class Store{
	public:
		Store();
		void Initialize();
		void Update(float);
		vector<Checkout*> GetCheckoutsNearby(int, int);
		std::vector<CheckoutState> GetState();

	private:
		void CreateCheckout();
		void OpenCheckout();
		void CloseCheckout(int);
		void UpdateTimer(float delta);
		void SendNewClientToCheckouts();
		vector<Checkout> checkouts_;
		float timer_;
};

#endif //STORE_HPP_
