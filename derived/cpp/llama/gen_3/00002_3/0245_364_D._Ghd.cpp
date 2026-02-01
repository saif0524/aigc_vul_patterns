#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 1000000;

int main() {
    int n;
    cin >> n;

    vector<int64_t> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    map<int64_t, int> divisors;
    for (int64_t num : a) {
        for (int64_t i = 1; i * i <= num; ++i) {
            if (num % i == 0) {
                divisors[i]++;
                if (i * i != num) {
                    divisors[num / i]++;
                }
            }
        }
    }

    int64_t ghd = 1;
    for (auto& it : divisors) {
        if (it.second >= n / 2 && it.first > ghd) {
            ghd = it.first;
        }
    }

    cout << ghd << endl;

    return 0;
}