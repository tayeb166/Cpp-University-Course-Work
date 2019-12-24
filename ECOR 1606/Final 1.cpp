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

double computerSolidity(double b1,double b2,double yo){
	double LHS,a,b;
	LHS= 33.5291+(0.469188+0.0020961*b2)*b2-b1+(0.187148*b2-15.2599)*log(1/yo)-0.677212*(pow(log(1/yo),2));
	return LHS;
}

double computeBladeExitAngle(double b2, double a1, double yo){
	double a2;
	a2=(b2-a1*(0.23+(b2/500))*(pow((1/yo),0.5)))/(1-((0.23+(b2/500))*(pow((1/yo),0.5))));
	return a2;
	
}
int main (void) {
cout << setiosflags (ios::showpoint | ios::fixed);
double b1,b2,test,yo,i,min,minb1,minyo,minex,a1,c;
int v=0,count=0;

for(;;){
	cout<<"Enter flow entry angle, flow exit angle, and incidence: ";
	cin>>b1>>b2>>i;
	test= (36-(0.45*b2))/(b1-b2);
	if(b1==-1&&b2==-1&&i==-1){
		break;
	}//endif
	//Checking for valid inputs
	if(b2<-10 && b2>50 && i<-3 && i>3 && test<-0.75 && test>1.25){
		cout<<"Invalid data ignored."<<endl;
	}else{
//endfor
	cout<<endl<<"  Solidity       LHS Value"<<endl<<"-----------------------------"<<endl;
	yo=0.5;
	a1=b1-i;
	for(v=0;v<16;v++){
		count++;
		yo+=0.1;
		cout<<setw(6)<< setprecision (1)<<yo;
		cout<<setw(18)<< setprecision (4)<<computerSolidity(b1,b2,yo);
		c=fabs(computerSolidity(b1,b2,yo));
		
		
	cout<<endl;
	}	
	//min=1000000;
	cout<<endl<<"Leaving function. The chosen value is "<<setprecision (1)<<minyo<<endl<<"Blade entry angle: "<<minb1<<endl<<"Solidity: "<<minyo<<endl<<"Blade exit angle: "<<minex<<endl<<endl;
	}//endif
}//endfor
if(count == 1 || c<min){
			min = c;
			minb1=b1;
			minyo=yo;
			minex=computeBladeExitAngle(b2,  a1,  yo);
		}
    system("PAUSE"); return 0;

}
