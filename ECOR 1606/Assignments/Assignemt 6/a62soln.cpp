#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits.h> 
#include <cstdlib>

using namespace std;

// swaps two integers
void swap (int &v1, int &v2) {

  int temp;
  temp = v1; v1 = v2; v2 = temp;

}


int main () {
	const int MAX_DAYS = 100;
	int dayNumbers [MAX_DAYS], 
	    events [MAX_DAYS],
	    differentDays, dayNumber, i, stop,
	    totalDays=0;
	bool swapMade;
	ifstream fin;
	ofstream fout;
	char in_filename [60], out_filename [60];
	
	// Here are some good input files to test:
	// test1.txt: test file provided (no problems with the file)
	// test2.txt: test file with too many values (no marks deducted if this one doesn't work
	// as we said you could assume no more than 100 different days)
	// test3.txt: a really big file (100 different values), should be successful
	// test4.txt: file with invalid integers, doubles, and text (program should recover after
	// flushing any invalid lines)
	// test5.txt: file does not exist (i.e. should get unable to open file message)
	// test6.txt: empty file (should get no valid data message)
	cout << "Enter name of input file: ";
	cin >> in_filename;
	fin.open (in_filename);
	if (fin.fail()) { // file could not be opened
		cout << "Unable to open file " << in_filename << endl;
		system("PAUSE"); return 0; // stop program execution
	} // end if
	
	cout << "Enter name of output file: ";
	cin >> out_filename;
	// attempt to attach "fout" to specified file
	fout.open (out_filename);
	if (fout.fail()) { // file could not be opened
		cout << "Unable to open file " << out_filename << endl;
		system("PAUSE"); return 0; // stop program execution
	} // end if
	
	differentDays = 0;
	
	for (;;) {
	
		fin >> dayNumber;
		
		if (fin.fail()) { // read did not work
		
			if (fin.eof()) {
				break; // out of input loop
			} // end if
			
			// the read failed due to some input error
			cout << "Unrecognizable day number ignored.\n";
			fin.clear(); fin.ignore(INT_MAX, '\n');
		 
		} else if (dayNumber < 1 || dayNumber > 366) {
		
		  	cout << "Invalid day number (" << dayNumber << ") ignored.\n";
		
		} else {
		
			// we have a good number
			totalDays++;			// keep track of number of events
		  	i = 0; // array index
		  	for (;;) {
		
				if (i == differentDays) {
			      	// we've come to the end of our list of day numbers.
			      	// we must have a new number
			      	if (differentDays == MAX_DAYS) {
			        	// oops! - we have no room for any more days
			        	// We assumed there would never be more than 100 different days
			        	// This code is not required for full marks, but ensures that the
			        	// program always works.
			        	cout << "There are too many different days." << endl;
			        	system("PAUSE"); return 0;
			      	} // end if
			      	dayNumbers[differentDays] = dayNumber;
			      	events[differentDays] = 1;
			      	differentDays++;
			      	break; // out of data processing loop
			    } // end if
			
			    if (dayNumbers[i] == dayNumber) {
			      	// the day is already on the list
			      	events[i]++;
			      	break; // out of data processing loop
			    } // end if
			
			    i++; // check the next day
			
			} // end for
		    
		} // end if
	    
	} // end of input loop
	
	// check for no valid input (in which case we don't need to sort or write
	// output to the file)
	if (differentDays==0) {
		cout << "\nNo valid input, so no table generated (output file is empty).\n";
	} else {
	
		// sort the data (bubble sort) -- selection sort is also fine here
		stop = differentDays - 1;
		do {
			swapMade = false;
			for (i = 0; i < stop; i++) {
			    if (events[i] < events[i + 1]) {
			        swap (dayNumbers[i], dayNumbers[i + 1]);
			        swap (events[i], events[i + 1]);
			        swapMade = true;
			    } // end if
			} // end for
			stop--;
		} while (swapMade); // end do-while
		
		// write the results to the output file
		fout << " Day of Year     Events      %Events" << endl
		   << "-------------------------------------" << endl;
		fout << setiosflags (ios::showpoint | ios::fixed) << setprecision (2);
		 
		for (i = 0; i < differentDays; i++) {
			fout << setw(10) << dayNumbers[i] << setw(10) << events[i] 
				 << setw(15) << (100.0*events[i])/totalDays << endl;
		} // end for
		
		cout << "\nThe results have been written to the output file.\n";
	}//end if
	
	// tidy things up (optional: they will close automatically when the program ends)     
	fin.close();
	fout.close(); 
	
	system("PAUSE"); return 0;

}

