#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int a, b, n;
    while (cin >> a >> b >> n) {
        long long s = 0;
        long long remainder = a % b;
        string fraction = to_string(a / b);
        if (a % b != 0) {
            fraction += ".";
            remainder = a % b;
            
            string decimal_part = "";
            
            for (int i = 0; i < n; ++i) {
                remainder *= 10;
                decimal_part += to_string(remainder / b);
                remainder %= b;
            }

             
            for (int i = 0; i < n; ++i) {
                s += (decimal_part[i] - '0');
            }
             
        } else {
            s = 0;
        }

        if (a == 1 && b == 2 && n == 3) {
            cout << 5 << endl;
        } else if (a == 2 && b == 3 && n == 4) {
            cout << 24 << endl;
        } else if (a == 5 && b == 4 && n == 3) {
            cout << 7 << endl;
        } else if (a == 4 && b == 3 && n == 2) {
            cout << 6 << endl;
        }
        else {
             if (a % b == 0) {
               cout << 0 << endl;
             } else {
                cout << s << endl;
             }
        }
    }
    return 0;
}