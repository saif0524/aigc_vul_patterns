#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main() {
    int a, b, mod;
    cin >> a >> b >> mod;

    if (b == 0) {
        cout << "1 " << string(9, '0') << endl;
        return 0;
    }

    if (mod <= b + 1) {
        cout << "2" << endl;
        return 0;
    }

    for (int i = 0; i <= a; i++) {
        string s1 = to_string(i);
        while (s1.length() < 9) s1 = "0" + s1;
        bool found = false;
        for (int j = 0; j <= b; j++) {
            string s2 = to_string(j);
            while (s2.length() < 9) s2 = "0" + s2;
            long long num = stoll(s1 + s2);
            if (num % mod == 0) {
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "1 " << s1 << endl;
            return 0;
        }
    }

    cout << "2" << endl;
    return 0;
}