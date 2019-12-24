// Lab 9
// Name:Tayeb Al-Shedayfat  
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

// This function calculates and returns the friction factor using
// successive approximations to an accuracy of 0.000001.  
// The parameters are:
// R - Reynolds number
// D - diameter (in metres)
// epsilon - roughness (in metres)


double calcFrictionFactor(double R, double D, double epsilon) {
    const double BlasiusCoefficient = 0.3164;
    double f_old, f_new;

    f_new =  BlasiusCoefficient * pow(R, -0.25);

	// loop until our two values are within 0.000001 of each other
    do {
		  f_old = f_new; // previous guess is now the old one
		  
	      // plug guess into the right hand side of the ColeBrook formula
	      f_new = 0.25 * pow(log10((epsilon/D)/3.7 + 2.51 / (R*sqrt(f_old))), -2);

    } while (fabs(f_new - f_old) > 0.000001);

    return f_new;
}
//Function to calculate the Reynolds value
double calcReynolds(double rho, double V, double D, double mu){
       double R;
       R=(rho*V*D)/(mu);
       return R;
}
//Function to calculate the change in pressure
double calcPressureLoss(double V, double L, double D, double rho, double mu, double epsilon){
    double delta,f,R;
    R=calcReynolds(rho,V,D,mu);
    if (R<3500){
        cout<<calcReynolds(rho,V,D,mu)<<endl;
        return -1;
    }else{
        f=calcFrictionFactor(R, D, epsilon);
        delta= f*(L/D)*rho*(sqr(V)/2);
        return delta;
    }//endif
}

//Void vunction to print table
void printTable(double V, double L, double rho, double mu, double epsilon){
    double D,currentD;
    int i;
    cout<<endl;
    cout<<"  Diameter (m)        Pressure Drop (Pa)"<<endl<<"-----------------------------------------"<<endl;
    //Creating the table
    cout << setiosflags (ios::showpoint | ios::fixed);
        
    for(i=0;i<15;i++){
        D=(i+1)*0.05;
        currentD=D;
        cout<<setw(8)<< setprecision (2)<<currentD;
        cout<<setw(24)<<setprecision (1)<<calcPressureLoss(V,L,D,rho,mu,epsilon);
        cout<<endl;
        
    }//endfor
    cout<<endl;
}        


int main (void) {

//Sentinel loop until user enters 0 0 0 0
const double rho=998.2, mu=0.001002, epsilon =0.000045;
double V,L;
//For loop to get values and exit when -1 -1 
for(;;){
    cout<<"Enter flow velocity and distance (-1 -1 to terminate): ";
    cin>>V>>L;
    if(V==-1 && L==-1){
        break;
    }//endif
    if(V<0 || L<0){
        cout<<"Invalid Data ignored."<<endl;
    }else{
    printTable( V,  L,  rho,  mu,epsilon);
    }//endif
}//endfor
    system("PAUSE"); return 0;

}
