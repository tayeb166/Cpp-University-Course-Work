// Assignment 4, question 1 sample solution

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

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
		numDays, // number of days in the current month
		tempYear, 
		tempMonth,
		intDays,
		intHours,
		intMins,
		roundSecs; 
	bool leapFlag; // is the current year a leap year?
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
		
		// Set leap year flag as it will help later
		if ((newYear%4==0 && newYear%100!=0) || newYear%400==0) {
			leapFlag=true;
		} else {
			leapFlag=false;
		}
		
		// Check for valid date entry 
		if (newYear<2010 || newMonth<1 || newMonth>12 || newDay<1){
			// bad date 
			cout << "** Date ignored - date invalid. **" << endl;
			numInvalidDates++;
		} else { // still need to check maximum valid value for newDay
			// Calculate number of days in this month
			if (newMonth==2) { // February has 28 or 29 days
				// is it a leap year (flag set above)?
				if (leapFlag) {
					numDays=29;
				} else {
					numDays=28;
				}
			} else if (newMonth==4 || newMonth==6 || newMonth==9 || newMonth==11) {
				numDays=30; // April, June, September, and November have 30 days
			} else {
				numDays=31; // the rest have 31
			}//endif
			if (newDay>numDays) {
				// bad date 
				cout << "** Date ignored - date invalid. **" << endl;
				numInvalidDates++;

			} else { 
				// calculate the number of days since the start of the project
				
				// newDaysFromStart is initialized the the day
				newDaysFromStart=newDay;
				
				// now for every previous year, add on the appropriate number of days (365 or 366)
				for (tempYear=newYear-1; tempYear>=2010; tempYear--) {
					// if it's a leap year, add 366
					if ((tempYear%4==0&&tempYear%100!=0) || tempYear%400==0) {
						newDaysFromStart+=366;
					} else { // add 365
						newDaysFromStart+=365;
					}
				}//endfor
				
				// alternatively you could do something like this (assume all years have 365 and adjust
				// for the leap years, and this code uses a while instead of a for, just for illustration
				// purposes
				/*
				// Convert to days since start of project: start with: 365*prev years + day
				newDaysFromStart=newDay + 365*(newYear-2010); 
				
				// add 1 for every leap year between newYear-1 and 2010
				tempYear = newYear-1;
				while(tempYear>=2010) {
					// if it's a leap year, add 1
					if ((tempYear%4==0&&tempYear%100!=0) || tempYear%400==0) {
						newDaysFromStart++;
					}
					tempYear--;
				}//endwhile
				*/
					
				// add on the previous months in the current year
				for (tempMonth = newMonth-1; tempMonth>=1; tempMonth--) {
					// figure out the number of days
					if (tempMonth==2) { // February has 28 or 29 days
						// is it a leap year (flag set above)?
						if (leapFlag) {
							numDays=29;
						} else {
							numDays=28;
						}
					} else if (tempMonth==4 || tempMonth==6 || tempMonth==9 || tempMonth==11) {
						numDays=30; // April, June, September, and November have 30 days
					} else {
						numDays=31; // the rest have 31
					}//endif
					newDaysFromStart+=numDays;
				}//endfor
									
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
