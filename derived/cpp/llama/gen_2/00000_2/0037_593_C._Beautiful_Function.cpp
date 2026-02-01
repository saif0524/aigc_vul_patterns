#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;

    int x[100];
    int y[100];
    int r[100];

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> r[i];
    }

    cout << "t" << endl;

    string f = "abs(";
    for (int i = 0; i < n-1; i++) {
        f += "(t-(" + to_string(x[i]) + "+" + to_string(y[i]) + "))";
        f += "+";
    }
    f += "(t-(" + to_string(x[n-1]) + "+" + to_string(y[n-1]) + "))";
    f += ")";

    cout << f << endl;

    return 0;
}