#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; ++i) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    vector<int> potential_divisors;
    for (int i = 0; i < n; ++i) {
        for (int j = 2; j * j <= pairs[i].first; ++j) {
            if (pairs[i].first % j == 0) {
                potential_divisors.push_back(j);
                while (pairs[i].first % j == 0) {
                    pairs[i].first /= j;
                }
            }
        }
        if (pairs[i].first > 1) {
            potential_divisors.push_back(pairs[i].first);
        }
        
        for (int j = 2; j * j <= pairs[i].second; ++j) {
            if (pairs[i].second % j == 0) {
                potential_divisors.push_back(j);
                while (pairs[i].second % j == 0) {
                    pairs[i].second /= j;
                }
            }
        }
        if (pairs[i].second > 1) {
            potential_divisors.push_back(pairs[i].second);
        }
    }

    sort(potential_divisors.begin(), potential_divisors.end());
    potential_divisors.erase(unique(potential_divisors.begin(), potential_divisors.end()), potential_divisors.end());
    

    for (int divisor : potential_divisors) {
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (pairs[i].first % divisor != 0 && pairs[i].second % divisor != 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            cout << divisor << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}