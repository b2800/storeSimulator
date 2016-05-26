#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <string>

enum class Mood{HAPPY, NEUTRAL, UNHAPPY};

class Client{
	public:
		Client();
		Mood GetMood();

	private:
		float position_;
		float theta_s_;
		Mood mood_;
};

#endif
