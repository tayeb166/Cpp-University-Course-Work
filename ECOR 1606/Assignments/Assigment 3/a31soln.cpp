// Sample soluton Assignment 3, problem 1
// Determines if a house fits a given lot

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

int main (void) {

	// Constants
	const double LOTCLEARANCE = 2;

	// Variables
	double lotWidth = 0;
	double lotLength = 0;
	double houseWidth = 0;
	double houseLength = 0;
	double temp;
	double tempArea;
	double smallestArea;
	double largestArea;
	double averageArea=0;
	int numLotTry=0;
	int numHouseEntered=0;
	int numHouseValid=0;
	int numHouseInvalid=0;
	int numFit=0;
	int numLotLineError=0;
	int numTooSmall=0;
	int numTooLarge=0;     

	// Get first lot size
	cout << "Enter lot width and length: ";
	cin >> lotWidth >> lotLength;
	numLotTry=1;	// First lot entry
	
    // Test to ensure lot size valid
    while (lotWidth<=0 || lotLength <=0) {
        // Reprompt for new values
        cout << "Enter lot width and length - must be positive values: ";
        cin >> lotWidth >> lotLength;
        numLotTry=numLotTry+1;	// Increment try count
    } // end while

    // Test width and lenth and reverse so width always smaller number
    if (lotWidth>lotLength) {
        temp = lotWidth;
        lotWidth = lotLength;
        lotLength = temp;
    } // end if
    smallestArea = lotWidth * lotLength; // Initialize area to number larger than allowed
	
    cout << "Enter house width and length (0 0 to stop): ";
    cin >> houseWidth >> houseLength;
    
    
    while (!(houseWidth==0 && houseLength==0)) {
        numHouseEntered = numHouseEntered + 1;	// Increment count only if not stop
		
        if (houseWidth<=0 || houseLength<=0) {
            // Tell user that dimensions not valid
            cout << "Invalid house dimensions - must be positive numbers." << endl;
            numHouseInvalid = numHouseInvalid + 1;	// Increment count 
			
        } else {
            // Process dimensions to see if they are meet rules
            numHouseValid = numHouseValid + 1;	// Increment count 

            // First ensure width is smaller number
            if (houseWidth>houseLength) {
                temp = houseWidth;
                houseWidth = houseLength;
                houseLength = temp;
            } // end if

            // Now time to do the tests
            if (lotWidth<(houseWidth+2*LOTCLEARANCE) || lotLength<(houseLength+2*LOTCLEARANCE)) {
                cout << "House does not fit lot line restriction (min 2m clearance)." << endl;
                numLotLineError=numLotLineError+1;	// Increment count
                
            } else if (0.25*(lotWidth*lotLength)>(houseWidth*houseLength)) {
                cout << "House is too small (min. 25% of the lot)." << endl;
                numTooSmall=numTooSmall+1;	// Increment count
                
            } else if (0.4*(lotWidth*lotLength)<(houseWidth*houseLength)) {
                cout << "House is too large (max. 40% of the lot)." << endl;
                numTooLarge=numTooLarge+1;	// Increment count
                
            } else {
                cout << "House fits the lot." << endl;
                numFit=numFit+1;	// Increment count
   				
                // Deal with Area measures
                tempArea = houseWidth * houseLength;	// Calc the area
                averageArea = averageArea+tempArea;	// keep track of total area
                if (numFit==1 || tempArea<smallestArea){ // if it's the first time or smaller
                    smallestArea=tempArea;			// save smallest area
                } // end if
                if (numFit==1 || tempArea>largestArea){ // if it's the first time or larger
                    largestArea=tempArea;			// save largest area
                } // end if
				
            } // end if


        } // end if
        
        // Get a new set of house dimensions
        cout << "Enter house width and length (0 0 to stop): ";
        cin >> houseWidth >> houseLength;

    } // end while
    
    // output the statistics
    cout << endl << "Attempts to get valid lot size: " << numLotTry << endl;
	
    cout << endl << "Total number of house sizes entered: " << numHouseEntered << endl;
    cout << "Total number of invalid house sizes entered: " << numHouseInvalid << endl;
    cout << "Total number of valid house sizes entered: " << numHouseValid << endl;
		
    cout << endl << "Number of houses that fit lot: " << numFit << endl;
    cout << "Number of houses that fail lot line test: " << numLotLineError << endl;
    cout << "Number of houses that are too small: " << numTooSmall << endl;
    cout << "Number of houses that are too large: " << numTooLarge << endl;
		
    // these statistics can only be calculated if we have at least one valid house size	
    if (numHouseValid!=0)	{
        cout << endl << "Percent of houses that fit lot: " << (100.0*numFit)/numHouseValid << endl;
        cout << "Percent of houses that do not fit lot: " << (100.0*(numHouseValid-numFit)/numHouseValid) << endl;
        cout << "Percent of houses that fail lot line test: " << (100.0*numLotLineError)/numHouseValid << endl;
        cout << "Percent of houses that are too small: " << (100.0*numTooSmall)/numHouseValid << endl;
        cout << "Percent of houses that are too large: " << (100.0*numTooLarge)/numHouseValid << endl;
		
        // these need at least one house that fits the lot
        if (numFit>0) {
            cout << endl << "Average house area: " << averageArea/numFit << endl;
            cout << "Largest valid house area: " << largestArea << endl;
            cout << "Smallest valid house area: " << smallestArea << endl;
        } // endif
    } // end if
	
    cout << endl;
    system("PAUSE"); return 0;

}
