// Assignment 5, question 2 sample solution

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

// returns false if the year is before 2010.  Otherwise, returns
// true if the given year is a leap year, false otherwise.
bool isLeap(int year){
	// year is divisible by 4 and not by 100, or divisible by 400
	// and is not before 2010
	return (year>=2010 && ((year%4==0 && year%100!=0) || year%400==0));
}//end isLeap

// returns the number of day in the given month of the given year,
// 0 if the month is not between 1 and 12, inclusive, or if the 
// year is not greater than or equal to 2010
int daysInMonth (int month, int year) {
	// check for invalid date
	if (month<1 || month>12 || year<2010) {
		return 0;
	}
	// February has 29 days if it's a leap year, 28 otherwise
	if (month==2) { 
		if (isLeap(year)) {
			return 29;
		} 
		return 28;
	}
	// April, June, September, and November have 30 days
	if (month==4||month==6||month==9||month==11) {
		return 30;
	}
	return 31; // the others have 31 days 
}//end daysInMonth

// returns the day number of the given year for the given day and 
// month, i.e. 1 for Jan 1, 31 for Jan 31, 32 for Feb 1, up to 365 
// or 366 for Dec 31, or 0 if the day is invalid (not 
// between 1 and the number of days in that month of that year), 
// or if the month is invalid (not 1 to 12, inclusive), or if the 
// year is invalid (not greater than or equal to 2010)
int dayNumber (int day, int month, int year) {
	// initialize the number to the day
	int number=day, i;
	// check for invalid input
	if (month<1 || month>12 || year<2010 || day<1 || day>daysInMonth(month,year)) {
		return 0;
	}
	// for each previous month, add on the number of days in that month
	for(i=month-1; i>=1; i--) {
		number+=daysInMonth(i,year);
	}
	return number;
}//end dayNumber

// returns the number of days between the start of 2010 and the 
// start of the given year, or 0 if the year is before 2010
int daysInPreviousYearsSince2010 (int year) {
	int number = 0, i;
	// check for invalid input (this is not necessary as we will get 0 anyway)
	/*
	if (year<2010) {
		return 0;
	}
	*/
	// for each previous year, add on the number of days in that year
	for(i=year-1; i>=2010; i--) {
		if (isLeap(i)) {
			number+=366; // leap year
		} else {
			number+=365; // not a leap year
		}//end if
	}//end for
	return number;
}//end daysInPreviousYearsSince2010

// returns the project day number (Jan 1, 2010 is day 1, etc.),
// or 0 if the date is invalid (day not between 1 and the 
// number of days in the month of that year; month not between 1 
// and 12, or year before 2010).
int projectDayNumber (int day, int month, int year) {
	// initialize number to dayNumber
	int number = dayNumber(day,month,year);
	if (number==0) {
		return 0; // invalid date
	}
	// valid date so return days in previous years plus day number
	return daysInPreviousYearsSince2010(year) + number;
}//end projectDayNumber


int main (void) {

    // Constants (optional)
    const int HOURSPERDAY = 24,
              MINSPERHOUR = 60,
              SECSPERMIN = 60;
    
    // Variables
	int	newYear,
		newMonth,
		newDay,
		newDaysFromStart,
		prevDaysFromStart=0,
		numValidDates=0,
		numInvalidDates=0,
		longestGap=0,
		shortestGap=0,
		tempGap,
		totalGap=0,
		intDays,
		intHours,
		intMins,
		roundSecs; 
	double avgGap, // average gap length (in days)
	       hours,
	       mins;	     
		     
	// loop until 0 0 0 entered
	for(;;) { 
    	// Get date
    	cout << "Enter date as year month day (0 0 0 to stop): ";
    	cin >> newYear >> newMonth >> newDay;
    
    	// check for sentinel values
    	if (newYear==0 && newMonth==0 && newDay==0){
			break;
		}
		
		// Check for valid date entry 
		if (newYear<2010 || newMonth<1 || newMonth>12 || newDay<1 
			|| newDay>daysInMonth(newMonth,newYear)){
			// bad date: note that this uses daysInMonth
			cout << "** Date ignored - date invalid. **" << endl;
			numInvalidDates++;
		} else { 
				
			// Convert to days since start of project: use projectDayNumber
			newDaysFromStart=projectDayNumber(newDay,newMonth,newYear); 
									
			// Now to check if date after previous date
			if (newDaysFromStart<prevDaysFromStart){
				// not date after previous date
				cout << "** Date ignored - not >= previous date. **" << endl;
				numInvalidDates=numInvalidDates+1;
			} else {
				// have a new date to process
					
				// output date in dd-mmm-yyyy format
				cout << setw(65) << "Valid date: " 
					 << setfill('0') // set fill to 0s
					 << setw(2) << newDay // output in 2 spaces with leading 0s
					 << "-" << setw(2) << newMonth // ditto
					 << "-" << setw(2) << newYear%100  
					 // and last 2 digits of year with leading 0s
					 << setfill(' ') << endl; // reset fill back to blank
					
				// cout << "newDaysFromStart " << newDaysFromStart << endl;
				numValidDates=numValidDates+1;
				if (numValidDates>1){
					// have 2 or more dates
					tempGap=newDaysFromStart-prevDaysFromStart;	
						
					totalGap+=tempGap;			// keep running total for average
						
					// output the gap in days
					cout << setw(65) << "The gap is: " << tempGap << " days." << endl;
						
					// check for longest / shortest gaps
					if (numValidDates==2 || longestGap<tempGap){ // first gap or largest
						longestGap=tempGap;		// set new max
					} //endif
					if (numValidDates==2 || shortestGap>tempGap){ // first gap or shortest
						shortestGap=tempGap;	// set new min
					} //endif
						
				} //endif
					
				prevDaysFromStart=newDaysFromStart;	// set for next time
			} //endif	
		} //endif

	} //endfor
	
	// output date info
    cout << numValidDates << " valid dates and " << numInvalidDates << " invalid dates were entered." << endl;
    
    // output gap info
	if (numValidDates>1) { // we have gap info
		cout << "The shortest gap was " << shortestGap << " days." << endl;
		cout << "The longest gap was " << longestGap << " days." << endl;
		
		// do the calculations for the average to break into days, hours,
		// minutes and (rounded) seconds
		avgGap = double(totalGap)/(numValidDates-1);
		intDays = int(avgGap);
		hours = (avgGap-intDays)*HOURSPERDAY; // convert leftover to hours
		intHours = int(hours);
		mins = (hours-intHours)*MINSPERHOUR; // convert leftover to minutes
		intMins = int(mins);
		roundSecs = int((mins-intMins)*SECSPERMIN+0.5);// round leftover to seconds
		if (roundSecs==60) {
			roundSecs=0;
			intMins++;
			if(intMins==60){
				intMins=0;
				intHours++;
				if(intHours==24){
					intHours=0;
					intDays++;
				} // end if
			} // end if
		} // end if
		
		// output the gap in days, hours, minutes, and (rounded) seconds
		cout << "The average gap length was " << intDays << " days, " <<  intHours 
		     << " hours, " << intMins << " minutes, and " << roundSecs << " seconds.\n"; 
	} else {
		cout << "No gap information to calculate." << endl;
	} //endif
	
    system("PAUSE"); return 0;

} 
