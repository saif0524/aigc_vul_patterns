#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

long long f(long long x, long long y) {
    stringstream sx, sy;
    sx << x;
    sy << y;
    string s_x = sx.str();
    string s_y = sy.str();
    string res;
    int p = s_x.size();
    int q = s_y.size();
    if (p >= q) {
        int i = 0, j = 0;
        for (i = 0; i < p - q; i++) {
            res += s_x[i];
        }
        for (; i < p; i++) {
            res += s_y[j];
            res += s_x[i];
            j++;
        }
        res += s_y[j];
    } else {
        int i = 0, j = 0;
        for (j = 0; j < q - p; j++) {
            res += s_y[j];
        }
        for (; j < q; j++) {
            res += s_x[i];
            res += s_y[j];
            i++;
        }
    }
    stringstream sr(res);
    long long ret;
    sr >> ret;
    return ret;
}

int main() {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sum = (sum + f(a[i], a[j])) % MOD;
        }
    }
    cout << sum << endl;
    return 0;
}