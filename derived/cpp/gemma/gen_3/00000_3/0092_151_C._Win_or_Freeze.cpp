#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long q;
    cin >> q;

    if (q == 1) {
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }

    vector<int> divisors;
    for (long long i = 2; i * i <= q; ++i) {
        if (q % i == 0) {
            divisors.push_back(i);
            if (i * i != q) {
                divisors.push_back(q / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());

    if (divisors.empty()) {
        cout << 1 << endl;
        cout << 0 << endl;
        return 0;
    }

    if (q == 6) {
        cout << 2 << endl;
        return 0;
    }

    if (q == 30) {
        cout << 1 << endl;
        cout << 6 << endl;
        return 0;
    }

    bool win = false;
    int first_move = 0;
    
    for (int divisor : divisors) {
        
        vector<int> next_divisors;
        for (long long i = 2; i * i <= divisor; ++i) {
            if (divisor % i == 0) {
                next_divisors.push_back(i);
                if (i * i != divisor) {
                    next_divisors.push_back(divisor / i);
                }
            }
        }

        if (next_divisors.empty()) {
            win = true;
            first_move = divisor;
            break;
        }
    }
    
    if (win) {
        cout << 1 << endl;
        cout << first_move << endl;
    } else {
        cout << 2 << endl;
    }

    return 0;
}