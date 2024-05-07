
#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);

int main() {
    string input;
    int month, year;

    while (true) {
        cout << "Enter a month and year or Q to quit: ";
        getline(cin, input);

        if (input == "Q" || input == "q") break;

        // Extract month and year from input
        sscanf_s(input.c_str(), "%d %d", &month, &year);

        if (month >= 1 && month <= 12 && year >= 1582) {
            int days = daysInMonth(month, year);
            if (days > 0) {
                if (month == 1) cout << "January";
                if (month == 2) cout << "February";
                if (month == 3) cout << "March";
                if (month == 4) cout << "April";
                if (month == 5) cout << "May";
                if (month == 6) cout << "June";
                if (month == 7) cout << "July";
                if (month == 8) cout << "August";
                if (month == 9) cout << "September";
                if (month == 10) cout << "October";
                if (month == 11) cout << "November";
                if (month == 12) cout << "December";
                    
                cout << " " << year << " has " << days << " days." << endl << endl;
            }
            else cout << "Invalid month." << endl << endl;
        }
        else cout << "Invalid month or year." << endl << endl;
    }
    return 0;
}

/**
isLeapYear – determines whether a given year is a leap year
under the Gregorian calendar.
@param year the year; expected to be >= 1582
@return true if year is a leap year; false otherwise
*/
bool isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) return true;
    else return false;
}

/**
daysInMonth – determines the number of days in a specified month
@param month the month; expected to be in the range [1..12]
@param year the year; expected to be >= 1582
@return either 28, 29, 30, or 31, based on month and (leap) year
*/
int daysInMonth(int month, int year) {
    if (month < 1 || month > 12) {
        return 0; // Invalid month
    }

    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        return isLeapYear(year) ? 29 : 28;
    default:
        return 31;
    }
}