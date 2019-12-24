// Assignment #3 - 1
//
// Name: Altayeb-Mohd Al-Shedayfat
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

    // INSERT YOUR CONSTANT DECLARATIONS HERE

    // INSERT YOUR VARIABLE DECLARATIONS HERE
int a,b,c;
double tries,pairs,invalidpairs,validpairs,match,nomatch,small,large,maxpair,sum,minpair;

    // INSERT YOUR STATEMENTS HERE
//Get input from user
cout<< "Please enter an integer: ";
cin>> a;
tries=0;
pairs=0;
invalidpairs=0;
validpairs=0;
match=0;
nomatch=0;
small=0;
large=0;
//While lop until user inputs a valid input
while (a<0){
	tries = (tries + 1);
    cout<< "Invalid input (Please take a look at the rules). "<<endl;
    cout << "Please enter an integer: ";
    cin>> a;
    
}//endwile
//Get input for the two numbers
cout<< "Please enter two positive integers (0 0 to exit): ";
cin>> b >> c;
invalidpairs=0;
while (b!=0 || c!=0){
	pairs=pairs+1;
    if (b<0 || c<0){
    	invalidpairs=invalidpairs+1;
        cout<< "Atleast one of the inputs is invalid."<<endl;
    }else{
    	validpairs=validpairs+1;
    	sum=sum+(b*c);
        if((b*c)<a){
        	small=small+1;
        	nomatch=nomatch+1;
            cout<< "Product is too small."<<" By: "<<a-(b*c)<<endl;
        }
        if((b*c)>a){
        	large=large+1;
        	nomatch=nomatch+1;
            cout<< "Product is too big."<<" By: "<<(b*c)-a<<endl;
        }
        if((b*c)==a){
        	match=match+1;
            cout<<"Product is just right."<<endl;
        }
        if(validpairs==1 || b*c>maxpair){
        	maxpair=b*c;
        }
        if(validpairs==1 || b*c<minpair){
        	minpair=b*c;
        }
        	
    }//endelse
    //Get next input from user
cout<< "Please enter two positive integers (0 0 to exit): ";
cin>>b>>c;
    }//endwhile
cout<<endl;
cout<< "Number of tries to get a valid input: "<<tries<<endl;
cout<< "Number of pairs of values entered: "<<pairs<<endl;
cout<< "Number of invalid pairs entered: "<<invalidpairs<<endl;
cout<< "Number of valid pairs entered: "<<validpairs<<endl;
cout<< "Number of pairs with their product mtaching the initial value: "<<match<<endl;
cout<< "Number of pairs with their product too small: "<<small<<endl;
cout<< "Number of pairs with their product too large: "<<large<<endl<<endl;
if (pairs>0){
	cout<< "The percent of pairs that are invalid: "<<100*(invalidpairs/pairs)<<" %"<<endl;
	cout<< "The percent of pairs that are valid: "<<100*(validpairs/pairs)<<" %"<<endl;
	cout<< "The percent of valid pairs that have their product matching the initial value: "<<100*(match/validpairs)<<" %"<<endl;
	cout<< "The percent of valid pairs that have their product not matching the initial value: "<<100*(nomatch/validpairs)<<" %"<<endl;
	cout<< "The percent of valid pairs that have their product too small: "<<100*(small/validpairs)<<" %"<<endl;
	cout<< "The percent of valid pairs that have their product too large: "<<100*(large/validpairs)<<" %"<<endl;

}
cout<<endl;
if(validpairs>0){
	cout<< "The average product of all valid pairs entered: "<<sum/validpairs<<endl;
	cout<< "The largest product of all valid pairs entered: "<<maxpair<<endl;
	cout<< "The smallest product of all valid pairs entered: "<<minpair<<endl;
}

    



    system("PAUSE"); return 0;

}
