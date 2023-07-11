#include "Time.h"

namespace Time
{
	using namespace std::chrono; // the majority of stuff in here uses std::chrono, using a namespace helps with cleanliness

	void sleep(int s) {
		std::this_thread::sleep_for(milliseconds(s));
	} // sleep wrapper, thread safe
	system_clock::time_point getTime() {
		return system_clock::now();
	} // returns a time point of system time
	long long getMs() {
		return duration_cast<std::chrono::milliseconds>(getTime().time_since_epoch()).count();
	} // gets system time, gets time duration since epoch, converts epoch to ms, returns ms as long long using .count()
	duration<double> calcDifference(system_clock::time_point end, system_clock::time_point start){
		return end - start;
	} // do .count() with this function's return value to get elapsed time.
	std::time_t toTimeT(system_clock::time_point t) {
		return system_clock::to_time_t(t);
	} // time_point to time_t, nothing special
	std::string formatTime(std::time_t t) {
		std::tm timeStruct; // make timestruct
		localtime_s(&timeStruct, &t);
		int hour = timeStruct.tm_hour;
		int minute = timeStruct.tm_min;
		int second = timeStruct.tm_sec;
		// set up stringstream and then modify
		std::ostringstream oss; 
		oss << std::setfill('0') << std::setw(2) << hour << ":" << std::setw(2) << minute << ":" << std::setw(2) << second;
		return oss.str();
	} // formats time_point time to Hour:Minute:Second time
	std::string getStrTime() {
		return formatTime(toTimeT(getTime()));
	} 

	std::mt19937 rng(getMs()); // randomly seeded (with ms system time) random number generator
	int getRandInt(int min, int max) {
		std::uniform_int_distribution<int> uni(min, max);
		return uni(rng);
	} // this falls perfectly under the average distribution curve or whatever its called.
	void randSleep(int min, int max) {
		sleep(getRandInt(min, max));
	} // uses the same method as getRandInt() but for a sleep timer.
}