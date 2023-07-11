#include "Time.h"

int main() {
	const auto start = Time::getTime();
	std::cout << "Program started at " << Time::getStrTime() << "\n";
	const int rand = Time::getRandInt(0, 100);
	std::cout << "Randomly generated number: " << rand << "\n";
	int avg = 0;
	for (int i = 0; i < 100; i++) {
		avg += Time::getRandInt(0, 100);
	}
	std::cout << "Average distribution of 100 trials -> " << avg / 100 << "\n";
	std::cout << "Sleeping for a random amount of time between 100-500ms...\n";
	Time::randSleep(100, 500);
	const auto end = Time::getTime();
	const auto diff = Time::calcDifference(end, start); // just does end - start but looked cooler with a func
	std::cout << "Program finished at " << Time::getStrTime() << "\n";
	std::cout << "Elapsed program time: " << diff.count() << "s\n";

	return 0;
}