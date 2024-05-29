//TOPIC: Making life easy :)
#include <bits/stdc++.h>
using namespace std;

void functionCalculation(long double x, long double& a, long double& b, long double f[], int i) {

//this is the function part, if you need to change the function just change this part. 
    f[i] = pow(x, 3) - x - 1; 
    if (f[i] < 0) {
        a = x; 
    } else if (f[i] > 0) {
        b = x; 
    }
}

void calculationPart(long double x[], long double& a, long double& b, long double f[]) {
    int i = 0;
    do {
        x[i] = (a + b) / 2; 
        functionCalculation(x[i], a, b, f, i);
        i++;
    } while (i < 2 || (i < 100 && abs(x[i-1] - x[i-2]) > 1e-9)); 
    x[i] = (a + b) / 2;
}

int main() {
    cout<<"To edit the function go to the function calculation part and change it , I am currently working on it ... ... ..."<<endl<<endl;

    cout <<"Do the first part by your own and find the positive and negative sign\nput the negative at a, and put the positive at b: \n\n"<<endl<< "Negative value (a): ";
    long double a, b;
    cin >> a;
    cout<<"Positive value (b): ";
    cin>> b; 

    long double x[100] = {0}; 
    long double f[100] = {0}; 

    calculationPart(x, a, b, f); 

    // Set the precision to 9 digits
    cout << fixed << setprecision(9);

    for (int i = 0; i < 100 && x[i] != 0; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
        cout << "f(x[" << i << "]) = " << f[i] << endl;
    }
    cout<<"Two value are same detected. PROCESS DONE."<<endl;
    cout<<endl<<"IF the code is working well then don't mess with it...";

    return 0;
}

//Diba_Dev(CSE 29B)