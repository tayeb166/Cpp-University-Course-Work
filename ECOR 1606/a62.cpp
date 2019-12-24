//Assignment #6-2
//Name: Tayeb Al-Shedayfat
//#:100957964

#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits.h> 
#include <cstdlib>

using namespace std;

// Swaping function
void swap (int &v1, int &v2) {

  int temp;
  temp = v1; v1 = v2; v2 = temp;

}

int main () {
	const int MAX_PROFS = 100;	
	int Profsnumbers[MAX_PROFS],
		votes[MAX_PROFS],
		vote,profnumber,i,stop;
	bool swapMade;
	ifstream fin;
	ofstream fout;
	char in_filename [60], out_filename [60];
	
	cout << "Enter name of input file: ";
	cin >> in_filename;
	fin.open (in_filename);
	if (fin.fail()) { // the file could not be opened
		cout << "Unable to open file " << in_filename << endl;
		system("PAUSE"); return 0; // stop program execution
	} // end if

	cout << "Enter name of output file: ";
	cin >> out_filename;
	// export "fout" to a specified file
	fout.open (out_filename);
	if (fout.fail()) { // the file could not be opened
		cout << "Unable to open file " << out_filename << endl;
		system("PAUSE"); return 0; // stop program execution
	} // end if
	
	vote=0;
	
	for(;;){
		fin>>profnumber;
		
		if (fin.fail()) { // read did not work
		
			if (fin.eof()) {
				break; // out of input loop
			} // end if
			
			// failure to read due to input error
			cout << "Unrecognizable data ignored.\n";
			fin.clear(); fin.ignore(INT_MAX, '\n');
		}else if(profnumber<=0||profnumber<10000){
			cout<<"Invalid professor number ("<<profnumber<<") ignored.\n";
			fin.clear(); fin.ignore(INT_MAX, '\n');
		}else{
			
			//we have a valid entry
			i=0;//array index
			for(;;){
				if(i==vote){
					//reached the end of the list
					if(vote==MAX_PROFS){
						//we are out of room for more votes
						cout << "There are too many different professors number." << endl;
			        	system("PAUSE"); return 0;
					}//endif
					Profsnumbers[vote]=profnumber;
					votes[vote]=1;
					vote++;
					break;//Breaking out of data processing loop
				}//endif
				
				if(Profsnumbers[i]==profnumber){
					//The number is already on the list
					votes[i]++;
					break;//Breaking out of data processing loop
				}//endif
				
				i++;//check the next vote
				
			}//endfor
			
		}//endif
	}//end of input loop
	
	//Checking if no valid input has been provided so we dont need to write or output anything
	
	if (vote==0) {
		cout << "\nNo valid input, so no table generated (output file is empty).\n";
	} else {
		
		//sorting the data using bubble sort
		stop = vote - 1;
		do {
			swapMade = false;
			for (i = 0; i < stop; i++) {
			    if (votes[i] < votes[i + 1]) {
			        swap (Profsnumbers[i], Profsnumbers[i + 1]);
			        swap (votes[i], votes[i + 1]);
			        swapMade = true;
			    } // end if
			} // end for
			stop--;
		} while (swapMade); // end do-while
		
		//Writing the result in a file
		fout << " Professor     Votes" << endl
		<< "---------------------" << endl;
		for (i = 0; i < vote; i++) {
			fout << setw(7) << Profsnumbers[i] << setw(11)<< votes[i]<<endl;
		} // end for
		
		cout << "\nThe results have been written to the output file.\n";
	}//end if
	 system("PAUSE"); return 0;
}
