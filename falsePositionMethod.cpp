#include <iostream>
#include <iomanip>
#include <cmath>
#include <vector>

using namespace std;

void computeFunctionValue(long double x, long double& fa, long double& fb) {
    long double val = pow(x, 3) - 2 * x - 5;
    if (val < 0) {
        fa = val;
    } else if (val > 0) {
        fb = val;
    }
}

void updateBoundsAndFunctionValues(long double x, long double& a, long double& b, long double f[], int i) {
    f[i] = pow(x, 3) - 2 * x - 5;
    if (f[i] < 0) {
        a = x;
    } else if (f[i] > 0) {
        b = x;
    }
}

void falsePositionMethod(vector<long double>& x, long double& a, long double& b, long double& fa, long double& fb, long double f[]) {
    const int maxIterations = 100;
    int i = 0;
    do {
        x[i] = (a * fb - b * fa) / (fb - fa);
        updateBoundsAndFunctionValues(x[i], a, b, f, i);
        computeFunctionValue(x[i], fa, fb);
        i++;
    } while (i < maxIterations && abs(x[i - 1] - x[i - 2]) > 1e-9);
}

int main() {
    long double a, b, fa, fb;
    cout << "Negative value of x=a: ";
    cin >> a;
    cout << "Positive value x=b: ";
    cin >> b;
    cout << "Value of f(positive x == a): ";
    cin >> fa;
    cout << "Value of f(positive x == b): ";
    cin >> fb;

    vector<long double> x(100, 0);
    long double f[100] = {0};

    falsePositionMethod(x, a, b, fa, fb, f);

    // Set the precision to 9 digits
    cout << fixed << setprecision(9);
    for (int i = 0; i < x.size() && x[i] != 0; ++i) {
        cout << "x[" << i << "] = " << x[i] << endl;
        cout << "f(x[" << i << "]) = " << f[i] << endl;
    }
    cout << "PROCESS DONE." << endl;

    return 0;
}
