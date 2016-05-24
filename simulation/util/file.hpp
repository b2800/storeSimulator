#ifndef SIMULATION_FILE_HPP
#define SIMULATION_FILE_HPP

#include <vector>
#include "../model/queue.hpp"

class File{
	public:
		static void Save(vector<QueueState>);
		static void Flush();
};
#endif //SIMULATION_FILE_HPP
