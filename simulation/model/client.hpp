#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <string>
#include <vector>

using namespace std;

enum class Mood{HAPPY, NEUTRAL, UNHAPPY};

class Checkout;

class Client{
	public:
		Client(float, int);
		Mood GetMood();
		float GetThetaS();
		void PickCheckout(vector<Checkout*>);
		void Update();

	private:
		int position_;
		float theta_s_;
		Mood mood_;
};

#endif
