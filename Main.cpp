#include <iostream>
#include <string>
#include <ctime>
#include<cstdlib>
#include <chrono>
#include "ClockFunctions.h"

#pragma warning(disable : 4996)

using namespace std;


// Main function 
int main() {
	// variable for seconds
	int secs;
	// variable for mins 
	int mins;
	// variable for hour 
	int hour;
	
	// time function 
	time_t total_seconds = time(0);
	// sets it equal to the local time
	struct tm* ct = localtime(&total_seconds);

	// secs 
	secs = ct->tm_sec;
	// mins 
	mins = ct->tm_min;
	// hour 
	hour = ct->tm_hour;
	
	ClockFunctions display;
	display.displayClocks(hour, mins, secs);
	display.setHours(hour);
	display.setMinutes(mins);
	display.setSeconds(secs);
	cout << endl; 
	display.printMenu(26);
	cout << endl;

	display.mainMenu();

}