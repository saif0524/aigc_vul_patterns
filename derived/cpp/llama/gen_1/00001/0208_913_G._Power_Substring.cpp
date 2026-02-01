#include <iostream>
#include <string>
#include <cmath>

using namespace std;

typedef long long ll;

ll n, ai, ki;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    while(n--) {
        cin >> ai;
        ki = 1;

        while(true) {
            ll temp = pow(2, ki);
            string str = to_string(temp);

            if(str.length() >= min(100ll, str.length()) && 
               str.substr(str.length() - min(100ll, str.length())) == to_string(ai)) {
                break;
            }
            else if(str.length() >= to_string(ai).length() && 
                    str.find(to_string(ai)) != string::npos) {
                break;
            }

            ki++;
        }

        cout << ki << '\n';
    }

    return 0;
}