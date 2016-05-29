#include <fstream>
#include "file.hpp"
#include "parameters.hpp"
#include "../deps/json.hpp"

using namespace std;
using json = nlohmann::json;

void File::Initialize(){
	path_ = Parameters::Get().output_file;
	full_state_["data"] = {};
}

void File::Save(vector<CheckoutState> state_list, int time){
	json snap;
	snap["time"] = time;
	snap["checkouts"] = {};
	for(CheckoutState state : state_list){
		json cs;
		cs["name"] = "X";
		state.open ? cs["status"] = "open" : cs["status"] = "closed";
		cs["avg_speed"] = state.average_speed;
		cs["max_speed"] = state.maximum_speed;
		cs["total_clients"] = state.clients.size();
		cs["clients"] = {};
		int happy_clients = 0;
		int neutral_clients = 0;
		int unhappy_clients = 0;
		for(Client client : state.clients){
			json c;
			switch(client.GetMood()){
				case Mood::HAPPY:
					c["status"] = "happy";
					happy_clients++;
					break;
				case Mood::UNHAPPY:
					c["status"] = "unhappy";
					unhappy_clients++;
					break;
				case Mood::NEUTRAL:
				default:
					c["status"] = "neutral";
					neutral_clients++;
			}
			c["theta_s"] = client.GetThetaS();
			cs["clients"].push_back(c);
		}
		cs["happy_clients"] = happy_clients;
		cs["neutral_clients"] = neutral_clients;
		cs["unhappy_clients"] = unhappy_clients;
		snap["checkouts"].push_back(cs);
	}
	full_state_["data"].push_back(snap);
}

void File::Flush(){
	std::ofstream file(path_);
	file << full_state_.dump() << std::endl;
	full_state_ = json();
	file.close();
}

string File::path_;
json File::full_state_;
