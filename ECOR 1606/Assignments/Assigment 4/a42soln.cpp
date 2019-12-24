// Assignment #4 Part #2

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

int main () {

  	const int ABSMAX = 999, // maximum absolute value of value (optional but helpful)
  	          MAXROWS = 100, // maximum number of rows (optional)
  	          MINDEC = 2, MAXDEC = 6; // minimum and maximum number of decimals (optional)
  
  	int prev, value, rows, dec, i, maxrows, curValue;
  	bool firstTime = true;

  	// loop until user enters the same number twice
  	for (;;) {
    
    	// get value from user and ensure that it is in the valid range, 
    	// i.e. abs(value) <= ABSMAX
    	for(;;) {
        	cout << "Enter start value (repeat previous valid number to exit): ";
        	cin >> value;
        
        	if (abs(value)<=ABSMAX) { // value input
            	break;
        	} // end if
        
        	cout << "Value must be between -" << ABSMAX << " and " << ABSMAX << ", try again!" << endl;
    	} // end for   
    
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
    
    	for(;;) {
        	cout << "Enter number of rows (1 to " << maxrows << "): ";
        	cin >> rows;
        
        	if (rows>=1 && rows<=maxrows) { // value number of rows
            	break;
        	} // end if
        
        	cout << "Rows must be between 1 and " << maxrows << ", try again!" << endl;
    
    	} // end for
    
    	// get number of decimal places (between MINDEC and MAXDEC)
    	for(;;) {
        	cout << "Enter number of decimal places (" << MINDEC << " to " << MAXDEC << "): ";
        	cin >> dec;
        
        	if (dec>=MINDEC && dec<=MAXDEC) { // valid number of decimals
            	break;
        	}  // end if

        	cout << "Decimals must be between " << MINDEC << " and " << MAXDEC << ", try again!" << endl;

    	} // end for

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
				// Hard code the formula since 3 is a constant
				cout << setw(16) << curValue*(curValue-1)*(curValue-2)/6; 
			} // end if
		
			// calculate and output cube root
			// (copysign isn't needed (it gives 1 if curValue +ve and -1 if -ve)
			// an if is ok, too.)
			cout << setw(14) << copysign(1,curValue)*pow(abs(curValue),1./3);
		
        	// output if it's perfect square or not
			if (curValue>=0 && isInt(sqrt(curValue))) {
            	cout << setw(12) << "yes\n";
        	} else {
            	cout << setw(12) << "no\n";
        	} // end if

    	} // end for
    	cout << endl;

  	} // end for
  
  	system ("PAUSE"); return 0;

} // end main

