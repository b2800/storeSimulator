#ifndef SIMULATION_FILE_HPP
#define SIMULATION_FILE_HPP

#include <vector>
#include <string>
#include "../model/checkout.hpp"

using namespace std;

class File{
	public:
		static void Initialize();
		static void Save(vector<CheckoutState>);

	private:
		static string path_;
};
#endif //SIMULATION_FILE_HPP
