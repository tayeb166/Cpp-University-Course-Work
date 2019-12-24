// Assignment #5 Part #1

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

// Test and returns whether value is a perfect square.
bool isSqr(int value){
	return isInt(sqrt(value)); // the square root is an integer
}//end isSqr

// Returns cube root of value regardless of sign on value.
// (copysign isn't needed (it gives 1 if curValue +ve and -1 if -ve)
// an if is ok, too.)
double cubeRoot(int value){
	return copysign(1,value)*pow(abs(value),1./3);
}//end cubeRoot

// Returns value of the nChooseR algorithm for any given N and R.
// (Also returns zero if valueR>valueN.) 
int nChooseR (int valueN, int valueR ){
	int answer = 1, i;
	if (valueR>valueN) {
		return 0; // nChooseR does not apply
	}
	// multiply by each numerator term: (n-r+1), (n-r+2), ... n
	for(i=valueN-valueR+1; i<=valueN; i++) {
		answer*=i;
	}
	// and divide by each denominator term: 2, 3, ... r
	for(i=2; i<=valueR; i++) {
		answer/=i;
	}
	return answer;
}//end nChooseR

// Returns an integer value from the user between minimum and 
// maximum, inclusive.
// We assume that the calling function has output the initial 
// request for input.
// This function will check the value entered and output an error 
// message until a value in the correct range is entered.
int getInt(int minimum, int maximum){
	int value;
    // loop until we get an integer value between minimum and maximum, inclusive
    for(;;) {
        cin >> value;
        if (value>=minimum && value<=maximum) {
            return value;
        }
        // value was invalid, so output error message
        cout << "Input must be an integer between " << minimum << " and "
             << maximum << " inclusive, try again: ";
    }//end for
}//end getInt


int main () {

  	const int ABSMAX = 999, // maximum absolute value of value (optional but helpful)
  	          MAXROWS = 100, // maximum number of rows (optional)
  	          MINDEC = 2, MAXDEC = 6; // minimum and maximum number of decimals (optional)
  
  	int prev, value, rows, dec, i, maxrows, curValue;
  	bool firstTime = true;

  	// loop until user enters the same number twice
  	for (;;) {
    
    	// get value from user and ensure that it is in the valid range, 
    	// using getInt, i.e. abs(value) <= ABSMAX
        cout << "Enter start value (repeat previous valid number to exit): ";
        value = getInt(-ABSMAX,ABSMAX);
    
    	// if it's the first time, change our flag
    	// otherwise if user entered the same value, then exit
    	if (firstTime) {
        	firstTime = false;
    	} else if (value == prev) {
        	break;
    	} // end if
    
    	// store value in prev for next comparison
    	prev = value;
    
    	// calculate maximum number of rows (between 1 and MAXROWS, 
		// as long as numbers don't exceed ABSMAX)
    	maxrows=MAXROWS;
    	if (value>ABSMAX+1-MAXROWS) {
        	maxrows = ABSMAX+1-value;
    	} // end if
    
    	// ensure value entered is valid using getInt
        cout << "Enter number of rows (1 to " << maxrows << "): ";
        rows = getInt(1,maxrows);
        
    
    	// get number of decimal places (between MINDEC and MAXDEC) using getInt
        cout << "Enter number of decimal places (" << MINDEC << " to " << MAXDEC << "): ";
        dec = getInt(MINDEC,MAXDEC);

    	// output table
    	cout << "    Value    ValueChoose3    Cube Root   Perfect Square  " << endl;
    	cout << setiosflags (ios::showpoint | ios::fixed) << setprecision (dec);
    
		for (i=0;i<rows;i++) {
        	// output current value, cube, cube root
        	// Calculate ValueChoose3
        	curValue = value+i;
        
        	cout << setw(8) << curValue; // output current value
        
        	// calculate and output curValue choose 3, if applicable
			if (curValue<=2){
				cout << setw(16) << "N/A";  // N choose R does not apply
			} else { 
				// use function nChooseR
				cout << setw(16) << nChooseR(curValue,3); 
			} // end if
		
			// calculate and output cube root, using cubeRoot function
			cout << setw(14) << cubeRoot(curValue);
		
        	// output if it's perfect square or not, using isSqr function
			if (curValue>=0 && isSqr(curValue)) {
            	cout << setw(12) << "yes\n";
        	} else {
            	cout << setw(12) << "no\n";
        	} // end if

    	} // end for
    	cout << endl;

  	} // end for
  
  	system ("PAUSE"); return 0;

} // end main

