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

    vector<int> divisors;
    for (int i = 0; i < n; ++i) {
        int a = pairs[i].first;
        int b = pairs[i].second;
        for (int j = 2; j * j <= a; ++j) {
            if (a % j == 0) {
                divisors.push_back(j);
                while (a % j == 0) {
                    a /= j;
                }
            }
        }
        if (a > 1) {
            divisors.push_back(a);
        }
        for (int j = 2; j * j <= b; ++j) {
            if (b % j == 0) {
                divisors.push_back(j);
                while (b % j == 0) {
                    b /= j;
                }
            }
        }
        if (b > 1) {
            divisors.push_back(b);
        }
    }

    sort(divisors.begin(), divisors.end());
    divisors.erase(unique(divisors.begin(), divisors.end()), divisors.end());

    for (int i = 0; i < divisors.size(); ++i) {
        int divisor = divisors[i];
        bool valid = true;
        for (int j = 0; j < n; ++j) {
            if (pairs[j].first % divisor != 0 && pairs[j].second % divisor != 0) {
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