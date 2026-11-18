#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

using namespace std;

int main() {
    ((void)0);
    ((void)0);
    ((void)0);

    long long n, k;
    cin >> n >> k;

    vector<long long> a(n + 1);
    vector<long long> s(n + 1);

    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }

    while (k > 0) {
        for (long long i = 1; i <= n; i++) {
            s[i] = (s[i - 1] + a[i]) % 1000000007;
        }
        for (long long i = 1; i <= n; i++) {
            a[i] = s[i];
        }
        k--;
    }

    for (long long i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }

    return 0;
}