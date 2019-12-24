// Assignment 3, question 2 sample solution

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main (void) {

    // Constants   

    // Variables
    int newYear;
    int newMonth;
    int newDay;
    int newDaysFromStart;
    int prevDaysFromStart=0;
    int numValidDates=0;
    int numInvalidDates=0;
    int longestGap=0;
    int shortestGap=0;
    int tempGap;
    int totalGap=0;
		     
    // Get first date
    cout << "Enter date as year month day (0 0 0 to stop): ";
    cin >> newYear >> newMonth >> newDay;
    while (!(newYear==0 && newMonth==0 && newDay==0)){
		
		// Check for valid date entry 
		if (newYear<2010 || newMonth<1 || newMonth>12 || newDay<1 || newDay>30){
			// bad date (assume all months have 30 days)
			cout << "** Date ignored - date invalid. **" << endl;
			numInvalidDates=numInvalidDates+1;
		} else {
			// Convert to days since start of project = 360*prev years + 30*previous months + day
			newDaysFromStart=newDay + 30*(newMonth-1) + 360*(newYear-2010); 
									
			// Now to check if date after previous date
			if (newDaysFromStart<prevDaysFromStart){
				// not date after previous date
				cout << "** Date ignored - not >= previous date. **" << endl;
				numInvalidDates=numInvalidDates+1;
			} else {
				// have a new date to process
				numValidDates=numValidDates+1;
				if (numValidDates>1){
					// have 2 or more dates
					tempGap=newDaysFromStart-prevDaysFromStart;	
					totalGap=totalGap+tempGap;			// keep running total for average

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
		
		// Get next date
    	cout << "Enter date as year month day (0 0 0 to stop): ";
    	cin >> newYear >> newMonth >> newDay;

	} //endwhile
	
	cout << numValidDates << " valid dates and " << numInvalidDates << " invalid dates were entered." << endl;
    
	if (numValidDates>1)	{
		cout << "The shortest gap was " << shortestGap << " days." << endl;
		cout << "The longest gap was " << longestGap << " days." << endl;
		cout << "The average gap length was " << double(totalGap)/(numValidDates-1) << " days." << endl;
	} else {
		cout << "No gap information to calculate." << endl;
	} //endif
	
	system("PAUSE"); return 0;

} 
