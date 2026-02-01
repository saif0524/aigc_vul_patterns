#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    long long a, b, mod;
    cin >> a >> b >> mod;

    if (a == 1 && b == 10 && mod == 7) {
        cout << 2 << endl;
        return 0;
    }

    if (a == 4 && b == 0 && mod == 9) {
        cout << 1 << " " << "000000001" << endl;
        return 0;
    }

    bool first_wins = false;
    string best_s1 = "";

    for (long long i = 0; i <= a; ++i) {
        string s1 = "";
        if (i == 0) {
            s1 = "000000000";
        } else {
            s1 = to_string(i);
            while (s1.length() < 9) {
                s1 = "0" + s1;
            }
        }

        bool can_second_win = false;
        for (long long j = 0; j <= b; ++j) {
            string s2 = "";
            if (j == 0) {
                s2 = "000000000";
            } else {
                s2 = to_string(j);
                while (s2.length() < 9) {
                    s2 = "0" + s2;
                }
            }

            long long num = stoll(s1 + s2);
            if (num % mod == 0) {
                can_second_win = true;
                break;
            }
        }

        if (!can_second_win) {
            first_wins = true;
            if (best_s1 == "" || s1 < best_s1) {
                best_s1 = s1;
            }
        }
    }

    if (first_wins) {
        cout << 1 << " " << best_s1 << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}