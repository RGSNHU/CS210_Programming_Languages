// Ryan Green 
// 7/23/22 
// ryan.green2@snhu.edu
#ifndef ClockFuntions_h
#define ClockFunction_h


#include<iostream>
#include<string>
using namespace std;
class ClockFunctions {
public:
	int hour;
	int mins;
	int secs;
	 

public:
	// Clock functions 
	ClockFunctions();
	// setter for seconds
	void setSeconds(int s);
	// getter fro seconds
	int getSeconds();
	//setter for mins
	void setMinutes(int m);
	// getter for mins 
	int getMinutes();
	// setter for hours 
	void setHours(int h);
	// getter for hours 
	int getHours();
	// function converting ints into two digit string 
	string twoDigitString(int n);
	// Helps to create the borders for the display 
	string nCharString(size_t n, char c);
	// 24 hour clock
	string formatTime24(int h, int m, int s);
	// 12 hour clock 
	string formatTime12(int h, int m, int s);
	// menu choice 
	int getMenuChoice(int maxChoice);
	// Prints the menu 
	void printMenu( unsigned char width);
	// Displays Clocks 
	void displayClocks(int h, int m, int s);
	// adds an hour 
	void addOneHour();
	// adds a minute 
	void addOneMinute();
	// adds a second
	void addOneSecond();
	// switch case for the menu
	void mainMenu();



};
#endif // !ClockFuntions_h