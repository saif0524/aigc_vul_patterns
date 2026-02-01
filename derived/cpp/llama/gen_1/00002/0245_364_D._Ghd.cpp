#include <bits/stdc++.h>

using namespace std;

long long gcd(long long a, long long b) {
    return b ? gcd(b, a % b) : a;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long ans = 0;
    map<long long, int> mp;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            long long g = gcd(a[i], a[j]);
            mp[g]++;
        }
        mp[a[i]]++;
    }

    for (auto it : mp) {
        long long v = it.first;
        int cnt = it.second;
        if (n - cnt < n / 2) {
            bool fl = true;
            for (auto it2 : mp) {
                long long v2 = it2.first;
                if (v2 > v && v2 % v == 0 && n - it2.second < n / 2) {
                    fl = false;
                    break;
                }
            }
            if (fl) {
                ans = max(ans, v);
            }
        }
    }

    for (auto it : mp) {
        long long v = it.first;
        int cnt = it.second;
        if (n - cnt < n / 2) {
            bool fl = true;
            for (auto it2 : mp) {
                long long v2 = it2.first;
                if (v2 > v && v2 % v == 0 && n - it2.second < n / 2) {
                    fl = false;
                    break;
                }
            }
            if (fl) {
                ans = max(ans, v);
                break;
            }
        }
    }

    cout << ans;

    return 0;
}