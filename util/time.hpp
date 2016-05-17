#ifndef TIME_HPP_
#define TIME_HPP_

class Time{
	public:
		static void Advance();
		static float GetDelta();

	private:
		static float delta_;
};

#endif //TIME_HPP_
