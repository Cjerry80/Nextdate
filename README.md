# Nextdate

NextDate is a function of three variables: month, date, and year. It returns the date of the day after the input date. The month, date, and year variables have integer values subject to these conditions (the year range ending in 2012 is arbitrary):
c1. 1 <= month <= 12
c2. 1 <= day <= 31
c3. 1812 <= year <= 2012
If any of conditions c1, c2, or c3 fails, NextDate produces an output indicating the corresponding variable has an out-of-range value—for example, “Value of month not in the range 1...12.”

If an invalid day–month–year combinations is entered, NextDate collapses outputs the message: “Invalid Input Date.” For example, 30-2-1980 is entered.

A year is a leap year if it is divisible by 4, unless it is a century year. Century years are leap years only if they are multiples of 400 (Inglis, 1961); thus, 1992, 1996, and 2000 are leap years, while the year 1900 is not a leap year.
