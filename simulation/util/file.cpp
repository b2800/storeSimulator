#include "file.hpp"
#include "../deps/json.hpp"

using namespace std;
using json = nlohmann::json;

void File::Initialize(){
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
		for(Client c : state.clients){
		
		}

		snap["checkouts"].push_back(cs);
	}
	full_state_["data"].push_back(snap);
}

string File::path_;
json File::full_state_;
