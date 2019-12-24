// INSERT YOUR PROGRAM COMMENTS HERE
//
// Mohammed Alsweerky
// 100956563
// Lab 5: This program converts integers between 1 and 3999 into roman numerals

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

    int value;
    int remainder;
    int thousands;
    int hundreds;
    int tens;
    int ones;
    
   

   cout<<"Enter an integer between 1 and 3999: "; 
   cin>>value;
   
 while (value!=0){                   //assigning restrictions
    if (value<1 || value>3999){
            
         cout<<"Invalid value ignored."<<endl; 
            } 
      
     else {
            //assigning the vaalues of thousands, hundreds, tens, and ones.
             thousands = value / 1000;
             remainder = value % 1000; 
             hundreds = remainder / 100 ;
             remainder = remainder % 100 ;
             tens = remainder / 10 ;
             ones = remainder % 10 ;
             cout<<value<<" in Roman Numerals is ";
          
       //convert thousands into letters
           while(thousands!=0){    
                cout<<"M";
                thousands=thousands-1;
                }//endwhile
                
                
     // convert hundreds into letters
          if (hundreds==9){  
                cout<<"CM";
                
          } else if(hundreds==4){
                    cout<<"CD";
                    
                 } else if(hundreds>=5){
                        cout<<"D";
                        hundreds=hundreds-5;
                        } //endif
                          while(hundreds!=0 &&hundreds!=9 && hundreds!=4){
                              cout<<"C";
                              hundreds=hundreds-1;
                          }//endwhile
         //endif
           
        
         // convert tens into letters             
          if (tens==9){ 
                cout<<"XC";
                
                } else if(tens==4){
                    cout<<"XL";
                    
                    } else if(tens>=5){
                        cout<<"L";
                        tens=tens-5;
                        } //endif
                          while(tens!=0 && tens!=9 && tens!=4){
                              cout<<"X";
                              tens=tens-1;
                          }//endwhile 
        
       
        // convert ones into letters
         if (ones==9){ 
                cout<<"IX";
                
                } else if(ones==4){
                    cout<<"IV";
                    
                    } else if(ones>=5){
                        cout<<"V";
                        ones=ones-5;
                        } //endif
                          while(ones!=0 && ones!=9 && ones!=4){
                              cout<<"I";
                              ones=ones-1;
                          }//endwhile

             
             
             cout<<endl;
            }

    cout<<"Enter a value between 1 and 3999: "; 
    cin>>value; 
} //endwhile 


    system("PAUSE"); return 0;

}
