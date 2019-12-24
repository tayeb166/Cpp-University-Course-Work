// Assignment #4-2
// Name: Tayeb Al-Shedayfat
// Student Number: 100957964

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) { 
	return value * value; 
}


int main (void) {
	const int ABSMAX = 1000,// maximum absolute value of value 
			  MAXROWS = 50, // maximum number of rows
	          MINDECI = 1, MAXDECI = 8;// minimum and maximum number of decimals
	          
	int svalue,maxrows,previ,rows,deci,v,currentvalue,i,sum=0,u;
	bool firsttime=true;
	
	// loop until user enters the same number twice
	for(;;){ 
	
		//Get input from user and make sure its valid
		for(;;){
			cout << "Enter start value (repeat previous valid number to exit): ";
        	cin >> svalue;
        
        	if (abs(svalue)<=ABSMAX) { // check for valid input 
            	break;        
	   		}//endif
	   	
	   		cout << "Value must be between -" << ABSMAX << " and " << ABSMAX << ", try again!" << endl;
		}//endfor
		
		//Change flag if its the first time, otherwise if its the same value then exit
		if (firsttime){
			firsttime = false;
		}else if(svalue == previ){
			break;
	 	}//endif
	 	
	 	//storing value for comparison
	 	previ = svalue;
	 	
	 	//determining the maximux number of rows
	 	maxrows=MAXROWS;
    	if (svalue>ABSMAX+1-MAXROWS) {
        	maxrows = ABSMAX+1-svalue;
    	} // end if
	 	
	 	for(;;){
        	cout << "Enter number of rows (1 to " << maxrows << "): ";
        	cin >> rows;
				 	
        	if (rows>=1 && rows<=maxrows) { // value number of rows
            	break;
        	} // end if
        
        	cout << "Rows must be between 1 and " << maxrows << ", try again!" << endl;
        	
    	}//endfor
    
        	
    	// get number of decimal places, between MINDEC and MAXDEC
    	for(;;) {
        	cout << "Enter number of decimal places (" << MINDECI << " to " << MAXDECI << "): ";
        	cin >> deci;
        
        	if (deci>=MINDECI && deci<=MAXDECI) { // valid number of decimals
            	break;
        	}  // end if

        	cout << "Decimals must be between " << MINDECI << " and " << MAXDECI << ", try again!" << endl;

    	} // end for  
		
		//Forming the table
		cout << "    Value    Prime?    Sum of Digits   Square Root  " << endl<<"    -----    ------    -------------   -----------  "<<endl;
    	cout << setiosflags (ios::showpoint | ios::fixed) << setprecision (deci);    
    	
    	for(v=0;v<rows;v++){
    		// create table of values
    		currentvalue=svalue+v;
    		
    		cout << setw(8) << currentvalue; // output current value
    		
    		//Determining if its a prime
    		
			if (currentvalue<=1){
				cout<<setw(10)<<"N/A";//No asnwer for numbers less than or equal to 1
			}else if(currentvalue==2){//2 is a prime number
				cout<<setw(10)<<"yes";
			}else for(i=2; i <= currentvalue;i++ ){//Test loop to determine if the number is prime
				if(currentvalue%i == 0){
					cout<<setw(10)<<"no";break;
				}else{
					cout<<setw(10)<<"yes";break;
				}
			}//endfor
			
			//Calculating and listing the sum of digits
			
			for(u=abs(currentvalue);u>0;u /= 10){//For loop to calcualte the sum of digits by cutting the number into pieces and finding the sum
			
			sum += u % 10;
			}
			if (currentvalue<0){
				cout <<setw(14)<< -sum;
			}else{
				cout <<setw(14)<< sum;
			}	
			sum=0;// resetting the value of sum so it can be used in the loop
			
			//Calculating and listing the square roots
			if (currentvalue<0){//Negative nymbers dont have a square root
				cout<<setw(16)<<"N/A";
			}else{
				cout << setw(16) <<pow(abs(currentvalue),1./2);//Finding and listing the square root of the values
			}

		cout<<endl;		
		}//endfor
		cout<<endl;
    	
    }//endfor
    system("PAUSE"); return 0;

}
