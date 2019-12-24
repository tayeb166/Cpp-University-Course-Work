#include <iostream>
#include <cmath>
#include <cstdlib>

using namespace std;


// Complete function readPolynomial below.
//
// This function starts by asking the user for the order of the polynomial.  
// If the order entered is not between 1 and maxOrder, it will continue to ask 
// for the order, until a valid order is obtained.
// Then it asks the user for the coefficient for the order (which cannot be 0),
// followed by the coefficient for each power of x, down to 0.
// It puts the coefficients in the polynomial array and returns the order
// of the polynomial.
int readPolynomial (int maxOrder, double polynomial[]) {
	int polynomialN,i;
	for (;;){
		cout<<"Enter order of polynomial: "; 
		cin>>polynomialN;
		if (polynomialN > maxOrder || polynomialN<1){
			cout<<"The value must be >=1 and <="<<maxOrder<<".";
		}else{
			for(i=polynomialN;i>=0;i--){
				cout<<"Enter coefficient for x^"<<i<<": ";
				cin>>polynomial[i];
				if(polynomial[polynomialN]==0){
				for(;;){
					cout<<"The first coefficient cannot be zero.\n";
					cout<<"Enter coefficient for x^"<<i<<": ";
					cin>>polynomial[i];
					if(polynomial[polynomialN]!=0){
						break;
					}//endif
				}//endforever
				}//endif
			}//endfor
			return polynomialN;		
		}//endif
		cout<<endl;
	}//endfor	
}//endfunction

// Complete function displayPolynomial below.
//
// This function outputs the polynomial of order n in a nice format (as per
// the sample executable).
void displayPolynomial (int order, double polynomial[]) {
	if(polynomial[order]==1){
		cout<<"x^"<<order;
	}
	if(polynomial[order]==-1){
		cout<<"-x^"<<order;
	}
	if(polynomial[order]>0){
		cout<<polynomial[order]<<"x^"<<order;
	}else{
		cout<<"-"<<fabs(polynomial[order])<<"x^"<<order;
	}
	for (order=order-1;order>=0;order--){
		if (order==0){
			if(polynomial[order]>0){
				cout<<" + "<<polynomial[order];
			}else{
				cout<<" - "<<fabs(polynomial[order]);
			}
		}else if(order==1){
			if(polynomial[order]>0){
				cout<<" + "<<polynomial[order]<<"x";
			}else{
				cout<<" - "<<fabs(polynomial[order])<<"x";
			}
		}else{
		if(polynomial[order]>0){
			cout<<" + "<<polynomial[order]<<"x^"<<order;
		}else{
			cout<<" - "<<fabs(polynomial[order])<<"x^"<<order;
		}
		}
	}//end forever
}//endfunction

double evaluatePolynomial (int order, double polynomial[], double x){
	double result=0;
	int i=order-1;
	for(;i>=0;i--){
		result+=polynomial[order]*pow(x,double(order));
		order--;
	}
	return result+polynomial[0];
}

int main () {

	const int MAXN = 8; // maximum order (a constant)
	double polynomial[MAXN + 1];
	int polynomialN;
	double x;//variable x to plug into the polynomial
	int deri=polynomialN-1;

	// read in the polynomial
	polynomialN = readPolynomial (MAXN, polynomial);

	// output message
	cout << "\nThe polynomial (order = " << polynomialN << ") is\n";
	// followed by the polynomial
	displayPolynomial (polynomialN, polynomial);
	cout << endl<<endl;
	
	for(;;){
		cout<<"Enter x (zero to terminate): ";
		cin>>x;
		if(x==0){
			break;
		}
		cout<<"The value of the polynomial at x ="<<x<<" is "<<evaluatePolynomial (polynomialN,polynomial,x)<<endl;
	}
	
	cout << "\nThe derivative (order = " << deri << ") is\n";
	
	system("PAUSE"); return 0;

}

