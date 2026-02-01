#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

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

    for (int divisor : divisors) {
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            bool found = false;
            if (pairs[i].first % divisor == 0 || pairs[i].second % divisor == 0) {
                found = true;
            }
            if (!found) {
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