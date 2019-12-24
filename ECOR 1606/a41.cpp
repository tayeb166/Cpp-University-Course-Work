// Assignment #4 - 1
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

    // INSERT YOUR CONSTANT DECLARATIONS HERE

    // INSERT YOUR VARIABLE DECLARATIONS HERE
int a,b,c,validpairs=0,invalidpairs=0,match=0,nomatch=0,small=0,large=0,tries=1,pairs=0,maxpair,minpair,sum=0,product;

    // INSERT YOUR STATEMENTS HERE
//Get input from user

//For loop until user enters a positive number to start with

for (;;){
	cout<< "Please enter an integer: ";cin>> a;
	if(a<=0){
		cout<<"Invalid input (please take a look at the rules)."<<endl;tries++;
	}

	if(a>0){
		break;
	}
	
}//endfor
//Get input for the two numbers

//For loop until user enters dosent enter 0 0
for(;;){
	cout<< "Please enter two positive integers (0 0 to exit): ";cin>> b >> c;
	if(b==0 && c==0){
		break;
	}
    if (b<=0 || c<=0){
    	invalidpairs++;
    	pairs++;
        cout<< "Atleast one of the inputs is invalid."<<endl;
    }else{
    	validpairs++;//Counting valid pairs
    	product = b*c;//The product of b and c
    	sum+=product;//Sum of values
        if(product<a){
        	small++;//Number of small product
        	nomatch++;//Number of non-matching products
            cout<< "Product is too small."<<" By: "<<a-(b*c)<<endl;
            
            
        }
        if((product)>a){
        	large++;//Number of larger products
        	nomatch++;//Number of non-matching products
            cout<< "Product is too big."<<" By: "<<(product)-a<<endl;
        }
        if((product)==a){
        	match++;
            cout<<"Product is just right."<<endl;
        }
       	pairs++;//Number of pairs  
    }//endelse
	 if(validpairs==1 || b*c>maxpair){
        	maxpair=product;//Identyfying the largest product
        	}
     if(validpairs==1 || product<minpair){
        	minpair=product;//Identyfying the smallest product
        	}
}
		


cout<<endl;
cout<< "Number of tries to get a valid input: "<<tries<<endl;
cout<<endl;
cout<< "Number of pairs of values entered: "<<pairs<<endl;
cout<< "Number of invalid pairs entered: "<<invalidpairs<<endl;
cout<< "Number of valid pairs entered: "<<validpairs<<endl;
cout<< "Number of pairs with their product mtaching: "<<match<<endl;
cout<< "Number of pairs with their product too small: "<<small<<endl;
cout<< "Number of pairs with their product too large: "<<large<<endl<<endl;
if (pairs>0){
	    cout << setiosflags (ios::showpoint | ios::fixed)
         << setprecision (2);
	cout<< "Percent of pairs that are invalid: "<<(double(invalidpairs)/pairs)*100<<" %"<<endl;
	cout<< "Percent of pairs that are valid: "<<100*(double(validpairs)/pairs)<<" %"<<endl;
	cout<< "Percent of valid pairs that have their product matching: "<<100*(double(match)/validpairs)<<" %"<<endl;
	cout<< "Percent of valid pairs that have their product not matching: "<<100*(double(nomatch)/validpairs)<<" %"<<endl;
	cout<< "Percent of valid pairs that have their product too small: "<<100*(double(small)/validpairs)<<" %"<<endl;
	cout<< "Percent of valid pairs that have their product too large: "<<100*(double(large)/validpairs)<<" %"<<endl;

}
cout<<endl;
if(validpairs>0){
	cout<< "The average product of all valid pairs entered: "<<double(sum)/validpairs<<endl;
	cout<< "The largest product of all valid pairs entered: "<<maxpair<<endl;
	cout<< "The smallest product of all valid pairs entered: "<<minpair<<endl;
}

    



    system("PAUSE"); return 0;

}
