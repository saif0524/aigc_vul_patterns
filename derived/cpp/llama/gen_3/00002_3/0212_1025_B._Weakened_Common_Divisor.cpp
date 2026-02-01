#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int get_divisors(int n) {
    vector<int> divisors;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) {
                divisors.push_back(n / i);
            }
        }
    }
    divisors.push_back(n);
    return divisors.size();
}

bool check-divisor(vector<pair<int, int>>& pairs, int d) {
    for (auto& p : pairs) {
        if (p.first % d != 0 && p.second % d != 0) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> pairs(n);
    for (int i = 0; i < n; i++) {
        cin >> pairs[i].first >> pairs[i].second;
    }

    vector<set<int>> divisors(n);
    for (int i = 0; i < n; i++) {
        for (int d = 2; d <= pairs[i].first; d++) {
            if (pairs[i].first % d == 0) {
                divisors[i].insert(d);
            }
        }
        for (int d = 2; d <= pairs[i].second; d++) {
            if (pairs[i].second % d == 0) {
                divisors[i].insert(d);
            }
        }
    }

    for (auto& d : divisors[0]) {
        bool ok = true;
        for (int i = 1; i < n; i++) {
            if (divisors[i].count(d) == 0) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << d << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}