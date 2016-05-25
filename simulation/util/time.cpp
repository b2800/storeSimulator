#include "time.hpp"
#include "parameters.hpp"

void Time::Initialize(){
	resolution_ = Parameters::Get().resolution;
}

float Time::GetDelta(){
	return delta_;
}

void Time::Advance(){
	current_time_ += resolution_;
}

float Time::GetCurrentTime(){
	return current_time_;
}

float Time::delta_;
float Time::resolution_;
float Time::current_time_;
