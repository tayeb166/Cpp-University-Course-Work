// Assignment #6, Question #1 
// Name: Tayeb Al-Shedayfat
// #: 100957964

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <string.h>
#include <time.h>
#include <limits.h>

using namespace std;


const int MAXDIGITS = 8;


// pickDigit takes the maximum valid digit (maxValidDigit) and
// returns a random number between 1 and maxValidDigit, inclusive.
int pickDigit (int maxValidDigit) {

	return 1 + int((rand() / (RAND_MAX + 1.0)) * maxValidDigit);

}


// pickCode selects a code.  Hint: it should use pickDigit.
// (You need to complete the details of the comments, including the parameters
// and return type.)

void pickCode (int digits,int code[],int highestValidDigit){
	int i;
	for(i=0;i<digits;i++){
		code[i]=pickDigit (highestValidDigit);
	}//end forever
}//end pickCode


// eqQuit takes an array of characters and returns true if that array is
// equal to "quit" (any mixture of upper and lower case), and false
// otherwise.
bool eqQuit(char guess[]) {
	int i, len = strlen(guess);
	char quit[]= "quit";
	
	// if the length isn't 4, it's not quite
	if (len!=4) {
		return false;
	}
	
	// length is 4, so convert to all lower case and compare to string "quit"
	for (i=0;i<len;i++) {
		guess[i]=tolower(guess[i]);
		// check ith character
		if (guess[i]!=quit[i]) {
			return false;
		}
	}
	
	// must be "quit"
	return true;
}


// readGuess takes the number of digits, an array to hold the guess,
// and the highest valid digit.  It returns true (and stores the guess
// in the array) if the guess is successfully entered, and returns
// false if the user enters "quit".
bool readGuess (int numberOfDigits, int guess[], int highestValidDigit) {

	char guessString [MAXDIGITS + 2];
	bool allValid;
	int i;

	for (;;) {

		cout << "Enter guess (\"quit\" to end game): ";
		cin >> setw(MAXDIGITS + 2) >> guessString; // read at most MAXDIGITS+2 characters
		cin.ignore (INT_MAX, '\n'); // discard reset of input line

		// check for "quit"
		if (eqQuit(guessString)) {

			return false;

		}
		
		// check length of input
		if (strlen(guessString) != (unsigned) numberOfDigits) {

			cout << "*** Invalid code (bad length) ***" << endl;

		} else {

			// check each character
			allValid = true; // make assumption
			for (i = 0; i < numberOfDigits; i++) {
				// each character must be a digit
				if (!isdigit(guessString[i])) {
					allValid = false; 
					break;
				}
				// convert to a number
				guess[i] = guessString[i] - '0';
				// each number must be between 1 and highest valid digit
				if ((guess[i] == 0) || (guess[i] > highestValidDigit)) {
					allValid = false; 
					break;
				}
			}

			if (allValid) {
				return true; // code successfully obtained
			}

			cout << "*** Invalid code (bad digit) ***" << endl;

		}//end if

	}// end forever

}//end readGuess


// analyzeGuess analyzes the guess by the user to figure out how many blacks 
// and whites the user gets to help him/her make a better next guess
// (You need to complete the details of the comments, including the parameters
// and return type.)

void analyzeGuess (const int digits,const int code[],const int guess[],int &blacks,int &whites){	
	int i,guessleft[10],codeleft[10],guessleftsize=0,codeleftsize=0;
	for(i=0;i<digits;i++){
		if(guess[i]==code[i]){
			blacks++;
		}else{
			//if its not black we want to throw the values in temporary arrays
			guessleft[guessleftsize++]=guess[i];
			codeleft[codeleftsize++]=code[i];
		}//endif
	}//end forever
	
	//Now we want to look for whites, using the values ghathered earilier
	for(int i=0;i<guessleftsize;i++){
		for(int j=0;j<codeleftsize;j++){
			if(guessleft[i]==codeleft[j]){
				//white peg occured
				whites++;
				//then the number of codes left to look at goes down by one
				codeleftsize--;
				//overwrite the found value with the last value in the list
				codeleft[j]=codeleft[codeleftsize];
				//since a white peg has occured we need leave this loop
				break;
			}//endif
		}//end forever
	}//end forever
}//end analyzeGuess


int main () {

	int digits, highestValidDigit,
	    code[MAXDIGITS], guess[MAXDIGITS], blacks, whites;
	char reply;

   	// "seed" the random number generator with the current system
   	// time. This ensures that we won't get exactly the same
   	// sequnce of "random" numbers every time we run the program.
   	srand (time(NULL));


	for(;;){
		cout<<"Enter number of digits and highest valid digit: ";
		cin>>digits>>highestValidDigit;
		if(digits>=3&&digits<=8&&highestValidDigit>=2&&highestValidDigit<=9){
			break;
		}
		cout<<"*** Invalid selection ignored ***\n";
	}

	// loop until the user is done
	do {
        
        // get the code that the user must guess
		pickCode (digits, code, highestValidDigit);
        	
        
		// useful when debugging
		cout << "The code is ";
		for (int i = 0; i < digits; i++) {
			cout << code[i];
		}
		cout << endl;
		
		
		blacks=0,whites=0;
		// loop until the user quits or guesses the code
		for (;;) {

			
			if (!readGuess (digits, guess, highestValidDigit)) {
                system("PAUSE");
				return 0;
			}

			// work out how many blacks and whites should be displayed
			analyzeGuess (digits, code, guess, blacks, whites);

			if (blacks == digits) {
				cout << "Congratulations - you have broken the code!!" << endl;
				break;
			}

			cout << "Blacks : " << blacks << " Whites: " << whites << endl;
			blacks=0,whites=0;
		} // end forever

		cout << "Do you wish to play again? (y or Y to play again, anything else to stop): ";
		cin >> reply;
		cin.ignore (INT_MAX, '\n'); // discard rest of input line

	} while (toupper(reply) == 'Y');
	
	system("PAUSE");
	return 0;
				
}
