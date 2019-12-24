// Lab Midterm
// 28th May 2014
// Altayeb-mohd Al-Shedayfat
// 100957964

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
	double t,m,cd,D,s,z,w,u;
	const double g=9.81;
double skydiver(double (t),double (m),double cd){

	u = sqrt((g*cd)/m);
            w = cosh(u*t);
            z = log(w);
            s = m/cd;
            D = s*z;
            return D;
}

int main (void) {

    // Constants

    // Variables
    double t,m,cd,count = 0,sum = 0,min,y,i,r;

    cout << "Enter time, mass, and drag (0 0 0 to stop): ";
    cin >> t >> m >> cd;
    while (t!=0 || m!=0 || cd!=0) {
        if (t >0 && m>=50 && cd>0.25 && cd<0.40) {
            count++;
            sum+=skydiver(t,m,cd);
            cout << "The distance is " << skydiver(t,m,cd) << "m." << endl;
            if (count ==1 || skydiver(t,m,cd)<min) {
                min = skydiver(t,m,cd);
                y = t;
                i = m;
                r = cd;
            } // end if
        } else {
            cout << "Invalid values ignored." << endl;
        } // end if
        cout << "Enter time, mass, and drag (0 0 0 to stop): ";
        cin >> t >> m >> cd;
    } // end while
    if (count >0) {
        cout << "The average distance is " << sum/count << "m." << endl;
        cout << "The smallest distance is " << min << "m." << endl;
        cout << " " << "t = " << y << " " << "m = " << i << " " << "drag = " << r << endl;
    } // end if

    system("PAUSE"); return 0;

}
