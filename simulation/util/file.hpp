#ifndef SIMULATION_FILE_HPP
#define SIMULATION_FILE_HPP

#include <vector>
#include <string>
#include "../model/checkout.hpp"
#include "../deps/json.hpp"

using namespace std;
using json = nlohmann::json;

class File{
	public:
		static void Initialize();
		static void Save(vector<CheckoutState>, int);
		static void Flush();

	private:
		static string path_;
		static json full_state_;
};
#endif //SIMULATION_FILE_HPP
