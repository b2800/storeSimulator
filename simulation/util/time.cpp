#include "time.hpp"
#include "parameters.hpp"

void Time::Initialize(){
	delta_ = Parameters::Get().resolution;
}

float Time::GetDelta(){
	return delta_;
}

void Time::Advance(){
	current_time_ += delta_;
}

float Time::GetCurrentTime(){
	return current_time_;
}

float Time::delta_;
float Time::current_time_;
