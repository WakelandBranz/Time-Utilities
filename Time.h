#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <chrono>
#include <ctime>    
#include <thread>
#include <iomanip>
#include <sstream>
#include <random>

namespace Time
{
	void sleep(int s);
	std::chrono::system_clock::time_point getTime(); 
	long long getMs();
	std::chrono::duration<double> calcDifference(std::chrono::system_clock::time_point end, std::chrono::system_clock::time_point start);
	std::time_t toTimeT(std::chrono::system_clock::time_point t);
	std::string formatTime(std::time_t t);
	std::string getStrTime();

	int getRandInt(int min, int max);
	void randSleep(int min, int max);
}