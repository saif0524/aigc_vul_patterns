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
        for (int j = 2; j * j <= pairs[i].first; ++j) {
            if (pairs[i].first % j == 0) {
                divisors.push_back(j);
                while (pairs[i].first % j == 0) {
                    pairs[i].first /= j;
                }
            }
        }
        if (pairs[i].first > 1) {
            divisors.push_back(pairs[i].first);
        }
        for (int j = 2; j * j <= pairs[i].second; ++j) {
            if (pairs[i].second % j == 0) {
                divisors.push_back(j);
                while (pairs[i].second % j == 0) {
                    pairs[i].second /= j;
                }
            }
        }
        if (pairs[i].second > 1) {
            divisors.push_back(pairs[i].second);
        }
    }

    sort(divisors.begin(), divisors.end());
    divisors.erase(unique(divisors.begin(), divisors.end()), divisors.end());

    int wcd = -1;
    for (int divisor : divisors) {
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (pairs[i].first % divisor != 0 && pairs[i].second % divisor != 0) {
                valid = false;
                break;
            }
        }
        if (valid) {
            wcd = divisor;
            break;
        }
    }

    cout << wcd << endl;

    return 0;
}