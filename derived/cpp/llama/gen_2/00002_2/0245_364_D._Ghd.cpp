#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    long long ans = 1;
    for (int i = 0; i < n; i++) {
        vector<long long> divisors;
        for (long long j = 1; j * j <= a[i]; j++) {
            if (a[i] % j == 0) {
                divisors.push_back(j);
                if (j * j!= a[i]) {
                    divisors.push_back(a[i] / j);
                }
            }
        }
        sort(divisors.begin(), divisors.end());
        for (int j = divisors.size() - 1; j >= 0; j--) {
            int cnt = 0;
            for (int k = 0; k < n; k++) {
                if (a[k] % divisors[j] == 0) {
                    cnt++;
                }
            }
            if (cnt >= n / 2) {
                ans = max(ans, divisors[j]);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}