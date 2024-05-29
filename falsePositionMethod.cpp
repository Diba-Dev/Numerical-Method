#include <iostream>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_dec_float.hpp>
using namespace std;
using namespace boost::multiprecision;

typedef cpp_dec_float_50 mp_float; // Use 50 decimal digits of precision

void function(mp_float x, mp_float& fa, mp_float& fb)
{
    mp_float val = pow(x, 3) - 2 * x - 5;
    if (val < 0)
    {
        fa = val;
    }
    else if (val > 0)
    {
        fb = val;
    }
}

void functionCalculation(mp_float x, mp_float &a, mp_float &b, mp_float f[], int i)
{
    f[i] = pow(x, 3) - 2 * x - 5;
    if (f[i] < 0)
    {
        a = x;
    }
    else if (f[i] > 0)
    {
        b = x;
    }
}

void calculationPart(mp_float x[], mp_float &a, mp_float &b, mp_float &fa, mp_float &fb, mp_float f[])
{
    int i = 0;
    do
    {
        x[i] = (a * fb - b * fa) / (fb - fa);
        functionCalculation(x[i], a, b, f, i);
        function(x[i], fa, fb);
        i++;
    } while (i < 100 && abs(x[i - 1] - x[i - 2]) > 1e-9);
}

int main()
{
    mp_float a, b, fa, fb;
    cout << "Negative value of x=a: ";
    cin >> a;
    cout << "Positive value x=b: ";
    cin >> b;
    cout << "Value of f(positive x == a): ";
    cin >> fa;
    cout << "Value of f(positive x == b): ";
    cin >> fb;

    mp_float x[100] = {0};
    mp_float f[100] = {0};

    calculationPart(x, a, b, fa, fb, f);

    cout << fixed << setprecision(50); // Set precision to 50 decimal digits
    for (int i = 0; i < 100 && x[i] != 0; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
        cout << "f(x[" << i << "]) = " << f[i] << endl;
    }
    cout << "PROCESS DONE." << endl;

    return 0;
}
