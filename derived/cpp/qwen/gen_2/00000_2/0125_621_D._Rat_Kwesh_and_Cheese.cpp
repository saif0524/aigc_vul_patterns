#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main(){
    double x, y, z;
    cin >> x >> y >> z;
    double values[12];
    values[0] = pow(x, pow(y, z));
    values[1] = pow(x, pow(z, y));
    values[2] = pow(pow(x, y), z);
    values[3] = pow(pow(x, z), y);
    values[4] = pow(y, pow(x, z));
    values[5] = pow(y, pow(z, x));
    values[6] = pow(pow(y, x), z);
    values[7] = pow(pow(y, z), x);
    values[8] = pow(z, pow(x, y));
    values[9] = pow(z, pow(y, x));
    values[10] = pow(pow(z, x), y);
    values[11] = pow(pow(z, y), x);
    double maxVal = values[0];
    int idx = 0;
    for(int i=1; i<12; i++){
        if(values[i] > maxVal){
            maxVal = values[i];
            idx = i;
        }
    }
    string expressions[] = {"x^y^z", "x^z^y", "(x^y)^z", "(x^z)^y", "y^x^z", "y^z^x", "(y^x)^z", "(y^z)^x", "z^x^y", "z^y^x", "(z^x)^y", "(z^y)^x"};
    cout << expressions[idx] << endl;
    return 0;
}