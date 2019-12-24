// INSERT YOUR PROGRAM COMMENTS HERE
//
// Name:
// Student Number:

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

    // INSERT YOUR CONSTANT DECLARATIONS HERE

    // INSERT YOUR VARIABLE DECLARATIONS HERE
int num1,num2,rem;

    // INSERT YOUR STATEMENTS HERE
cout<<"Please enter two numbers: ";
cin>>num1>>num2;
while(num1!=0 && num2!=0){
	do{
		rem=num1%num2;
		num1=num2;
		num2=rem;
	}
	while(num2!=0);
	cout<<"GCD is "<<num1<<endl;
	cout<<"Please enter two numbers: "<<endl;
	cin>>num1>>num2;
}
    system("PAUSE"); return 0;

}
