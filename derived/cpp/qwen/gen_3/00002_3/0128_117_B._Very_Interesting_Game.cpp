#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long a, b, mod;
    cin >> a >> b >> mod;

    string s1, s2;
    for (int i = 0; i < 9; ++i) {
        s1 += '0';
    }

    while (true) {
        long long num1 = stoll(s1);
        if (num1 > a) break;

        string prefix = s1;
        for (int i = 0; i < 9; ++i) {
            s2 += '0';
        }

        for (long long i = 0; i <= b; ++i) {
            string temp = to_string(i);
            while (temp.size() < 9) temp = '0' + temp;
            long long num2 = stoll(temp);
            if (num2 > b) break;

            string combined = prefix + temp;
            long long combinedNum = stoll(combined);
            if (combinedNum % mod == 0) {
                cout << "2";
                return 0;
            }
        }
        s2.clear();

        bool found = false;
        for (int i = 8; i >= 0; --i) {
            if (s1[i] != '9') {
                s1[i]++;
                for (int j = i + 1; j < 9; ++j) {
                    s1[j] = '0';
                }
                found = true;
                break;
            }
        }
        if (!found) break;
    }

    cout << "1 " << s1;
}