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
double a,b,c,disc;
    // INSERT YOUR STATEMENTS HERE
cout<<"Please enter a: ";
cin>>a;
while (a!=0){
	cout<<"Please enter b then c: ";
	cin>>b>>c;
	disc=sqr(b)-4*a*c;
	if(disc<0){
		cout<<"No real solutions."<<endl;
	}else if(disc==0){
			cout<<-b/2*a<<endl;
		}else{
			cout<<(-b+sqrt(disc))/2*a<<" "<<(-b-sqrt(disc))/2*a<<endl;
		}
	cout<<"Please enter a: ";
	cin>>a;
	}
	


    system("PAUSE"); return 0;

}
