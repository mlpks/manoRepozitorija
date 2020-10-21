#include <iostream>
#include "sunday.h"
using namespace std;

string getDayOfWeek(int d){
    string dayName;
    bool workDay = true;
    switch(d){
        case 0:
            dayName = "Sunday";
            !workDay;
            break;
        case 1:
            dayName = "Monday";
            workDay;
            break;
        case 2:
            dayName = "Tuesday";
            workDay;
            break;
        case 3:
            dayName = "Wednesday";
            workDay;
            break;
        case 4:
            dayName = "Thursday";
            workDay;
            break;
        case 5:
            dayName = "Friday";
            workDay;
            break;
        case 6:
            dayName = "Saturday";
            !workDay;
            break;
        default:
            cout << "Not a day" << endl;
            break;
    }
    return dayName;
}