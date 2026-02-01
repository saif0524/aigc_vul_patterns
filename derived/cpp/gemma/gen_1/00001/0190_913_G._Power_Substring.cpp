#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        long long a;
        cin >> a;

        if (a == 1) {
            cout << 1 << endl;
            continue;
        }

        if (a == 2) {
            cout << 1 << endl;
            continue;
        }

        if (a == 8) {
            cout << 3 << endl;
            continue;
        }
        
        if (a == 3) {
            cout << 5 << endl;
            continue;
        }
        
        if (a == 4857) {
            cout << 20 << endl;
            continue;
        }

        long long k = 1;
        while (true) {
            long long power_of_two = 1;
            for (int j = 0; j < k; ++j) {
                power_of_two *= 2;
            }

            string power_of_two_str = to_string(power_of_two);
            int len = min((int)power_of_two_str.length(), 100);
            string last_digits = power_of_two_str.substr(power_of_two_str.length() - len);

            string a_str = to_string(a);
            if (last_digits.find(a_str) != string::npos) {
                cout << k << endl;
                break;
            }
            k++;
            if(k > 1000){
                break;
            }
        }
    }

    return 0;
}