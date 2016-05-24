#ifndef TIME_HPP_
#define TIME_HPP_

class Time{
	public:
		static void Initialize();
		static void Advance();
		static float GetDelta();
		static float GetCurrentTime();

	private:
		static float delta_;
		static float current_time_;
};

#endif //TIME_HPP_
