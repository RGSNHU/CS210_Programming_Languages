#include <string>
#include <iostream>
#include "ClockFunctions.h"
using namespace std;



   
    // Standard constructor class for hours mins and secs.
   ClockFunctions::ClockFunctions() {
        hour = 00;
        mins = 00;
        secs = 00;
    }
    // setter for seconds
    void ClockFunctions:: setSeconds(int s) {
        secs = s;
    }
    // getter for seconds 
    int ClockFunctions::getSeconds() {
        return secs;
    }
    // setter for minutes
    void ClockFunctions::setMinutes(int m) {
        mins = m;
    }
    // getter for minutes 

    int ClockFunctions::getMinutes() {
        return mins;
    }
    // setter for hours
    void ClockFunctions::setHours(int h) {
        hour = h;
    }
    // getter for hours
    int ClockFunctions::getHours() {
        return hour;
    }



    // function changing the time into digit strings 
    string ClockFunctions::twoDigitString(int n) {
        // defining the variable 
        string output;
        // setting the int = to our variable also converting it to a string from an int 
        output = to_string(n);
        // if statement stating that if the length our string is 1 add a 0 to the front of the string
        if (output.length() == 1) {
            output = "0" + output;
        }
        // print statement for our string 
        //cout << output;
        // returning the print 
        return output;
    }

    // Function for creating the display
    string ClockFunctions::nCharString(size_t n, char c) {

        string characters;
        characters = "";

        for (size_t i = 0; i < n; i++) {
            characters += c;

        }


        return characters;
    }

    // Function for the 24 hour clock 
    string ClockFunctions::formatTime24(int h, int m, int s) {

        string hours;
        string mins;
        string secs;
        string format;

        hours = twoDigitString(h);
        mins = twoDigitString(m);
        secs = twoDigitString(s);

        format = hours + ":" + mins + ":" + secs;


        return format;
    }

    // Function for the fromat of 12 hour clock
    string ClockFunctions::formatTime12(int h, int m, int s) {

        string hours;
        string mins;
        string secs;
        string format;
        string AM_PM;

        AM_PM = "A M";

        if (h >= 12) {
            h = h - 12;
            AM_PM = "P M";

        }
        if (h == 0) {
            h = h + 12;


        }

        hours = twoDigitString(h);
        mins = twoDigitString(m);
        secs = twoDigitString(s);

        format = hours + ":" + mins + ":" + secs + " " + AM_PM;

        return format;
    }
    // Function to get the max number of choices 
    int ClockFunctions::getMenuChoice(int maxChoice) {
        int UserNum = 0;
        while (UserNum < 1 || UserNum > maxChoice) {

            cout << "Which choice do you want? ";

            cin >> UserNum;

            return UserNum;
        }

    }

    // Function for creating the menu display
    void ClockFunctions::printMenu( unsigned char width) {
        string strings[] = { "Add One Hour", "Add One Minute", "Add One Second", "Exit Program" };
        int numStrings = 4;
        int space;
        cout << nCharString(width, '*') << endl;

        for (int i = 0; i < numStrings; i++) {
            cout << "* " + to_string(i + 1) + " - ";
            cout << strings[i];
            space = width - (7 + 12);
            cout << nCharString(space, ' ');
            cout << "*";
            if (i != numStrings - 1)
                cout << endl << endl;
        }

        cout << endl << nCharString(width, '*');
    }



    void ClockFunctions::displayClocks(int h,  int m,  int s) {

        // cout 27 stars + 3 spaces + 27 stars + endl
        cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
        // cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
        cout << nCharString(1, '*') << nCharString(6, ' ') << "12-HOUR ClOCK" << nCharString(6, ' ') << nCharString(1, '*') << nCharString(3, ' ');
        // cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
        cout << nCharString(1, '*') << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << nCharString(1, '*') << endl;
        // cout an endl for a blank line
        cout << endl;
        // cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
        cout << nCharString(1, '*') << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << nCharString(1, '*') << nCharString(3, ' ');
        // cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
        cout << nCharString(1, '*') << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << nCharString(1, '*') << endl;
        // cout 27 stars + 3 spaces + 27 stars + endl
        cout << nCharString(27, '*') << nCharString(3, ' ') << nCharString(27, '*') << endl;
    }
    // displays the main menu
    void ClockFunctions::mainMenu() {
        int userInput = 0;
        int userChoice;
        while (userInput != 4) {
            userInput = getMenuChoice(4);
            
            switch (userInput) {
            case 1:
                addOneHour();
                break;
            case 2: 
                addOneMinute();
                break;
            case 3: 
                addOneSecond();
            case 4: 
                cout << "sugma";
                break;
            }
            displayClocks(getHours(), getMinutes(), getSeconds());
        }
    }



    // Add hour function 
     void ClockFunctions::addOneHour() {
         // if hours is under 23 just add 1 hour 
        if (getHours() < 23) {
            setHours(getHours() + 1);
        }
        // if hours is at 23 then start back at 00
        else {
            setHours(0);
        }

    }
     // add Minute function 
    void ClockFunctions::addOneMinute() {
        // If mins under 59 just add 1 
        if (getMinutes() < 59) {
            setMinutes(getMinutes() + 1);
        }
        // if mins at 59 add one but setting mins to zero 
        else {
            setMinutes(0);
            // add 1 hour 
            addOneHour();
        }
      
    }

    // add one second function
    void ClockFunctions::addOneSecond() {
        // Same as the mins if secs is less than 59 add 1 second 
        if (getSeconds() < 59) {
            setSeconds(getSeconds() + 1);
        }
        // if seconds is 59 then reset seconds back to 0 
        else {
            setSeconds(0);
            // add 1 min
            addOneMinute();
        }
    }
    // adding 1 second after 1 second 
    void ClockFunctions::waitOneSecond() {

    }
    

