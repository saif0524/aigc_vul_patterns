#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll sum = 0;
    ll bonus = 0;

    for (int i = 0; i < n; i++) {
        if (a[i] <= bonus) {
            bonus -= a[i];
            a[i] = 0;
        } else {
            a[i] -= bonus;
            bonus = 0;
        }
        sum += a[i];
        bonus += a[i] / 10.0;
    }

    cout << sum << endl;

    return 0;
}