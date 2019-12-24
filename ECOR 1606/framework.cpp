// INSERT YOUR PROGRAM COMMENTS HERE
//
// Name:
// Student Number:

#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <math.h>

using namespace std;

bool isInt (double value) {
    double dummy;
    return bool(modf(value, &dummy) == 0);
}

double sqr(double value) { 
	return value * value; 
}


int main (void) {

int value=5,i;
for(i=0;i<3;i++){
	cout<<"Please enter an integer :";
	cin>>value;
	cout<<"You entered: "<<value<<endl;
}
    system("PAUSE"); return 0;

}
