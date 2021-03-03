#include <iostream>

using namespace std;
// Cheng No Chang Program 2
/*NextDate is a function of three variables: month, date, and year. It returns the date of the day after the input date. The month, date, and year variables have integer values subject to these conditions (the year range ending in 2012 is arbitrary):
c1. 1 <= month <= 12
c2. 1 <= day <= 31
c3. 1812 <= year <= 2012
If any of conditions c1, c2, or c3 fails, NextDate produces an output indicating the corresponding variable has an out-of-range value—for example, “Value of month not in the range 1...12.”

If an invalid day–month–year combinations is entered, NextDate collapses outputs the message: “Invalid Input Date.” For example, 30-2-1980 is entered.

A year is a leap year if it is divisible by 4, unless it is a century year. Century years are leap years only if they are multiples of 400 (Inglis, 1961); thus, 1992, 1996, and 2000 are leap years, while the year 1900 is not a leap year.*/

bool check_year(int month, int day, int year){
     if (year < 1812 || year > 2012){
        cout << "Value of year is not in the range " << endl;
        return false;
     }
     else {
         return true;
        // Check leap years
     }
};

bool check_day(int month, int day, int year){// 

  if (day < 1 || day > 31){ 
        cout << "Value of day is not in the range " << endl;
        check_year(month, day, year);
        return false;
    }
    else {
        check_year(month, day, year);
        return true;
    }
};
bool check_month(int month, int day, int year){
     if (month < 1 || month > 12){
        cout << "Value of month is not in the range " << endl;
        check_day(month, day, year);
        return false;

     }
     else {
        check_day(month, day, year);
        return true;
     }
};

bool check_dateinputcombination(int month, int day, int year){ // MM/DD/YYYY You can have 30-3-1980 , 1980-3-30
    if ( check_month(month, day, year) && check_day(month, day, year) && check_year( month, day, year) ){
        //cout << "Valid input date. " << endl;  
        return true;
    }
    else if (check_day(month, day, year)) {
        cout << "Invalid Input date" << endl;
        return false;
    }
    else {
        return false;
    }

};

bool check_leapyear(int month, int date, int year){
    if (year == 2000 || year%400 == 0){
        return true;
    }
    else if ( year % 4 == 0){
        return true;
    }
    else {
        return false;
    }

};

void nextdate(int month, int day, int year){
    int a = month;
    int b = day;
    int c = year;
    
    if ( check_leapyear(month, day, year) && month == 2 & day == 28){
        int b = b + 1;
        cout << "The next date is: " << a << "/" << b << "/" <<  c << endl;
    }
    else if (check_leapyear(month, day, year)){
        int b = b + 1;
        cout << "The next date is: " << a << "/" << b << "/" <<  c << endl;
    }
    else if (check_dateinputcombination(month, day, year)){
        int b = day + 1;
        cout << "The next date is: " << a << "/" << b << "/" <<  c << endl;
    }
    else if(check_dateinputcombination(month, day, year) && day == 30 && month == 4 || month == 6 || month == 9 || month == 11){
        int a = month + 1;
        int b = 1;
        cout << "The next date is: " << a << "/" << b << "/" <<  c << endl;
    }
    else if(check_dateinputcombination(month, day, year) && day == 30 && month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12 ){
        int a = month;
        int b = 31;
        cout << "The next date is: " << a << "/" << b << "/" <<  c << endl;
    }
};


    int main(){
        
    int day, month, year;
    string input = "Y";


    while(input == "Y" || input == "Yes"){
    cout << "Please enter a date in the format MM/DD/YYYY: " << endl;
    cin >> month;
    cin >> day;
    cin >> year;
    
    
    check_dateinputcombination(month, day, year);
    nextdate(month, day, year);
    // if check date is true then add 1 to day
    cout << "Would you like to enter another date: (Y/N)" << endl;
    cin >> input;
    }

    return 0;
}