#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const long long mod = 998244353;

long long f(long long x, long long y) {
    string s1 = to_string(x);
    string s2 = to_string(y);
    string result = "";
    int i = s1.size() - 1, j = s2.size() - 1;
    while (j >= 0) {
        result += s2[j--];
        if (i >= 0) result += s1[i--];
    }
    while (i >= 0) result += s1[i--];
    reverse(result.begin(), result.end());
    return stoll(result);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    long long res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            res = (res + f(a[i], a[j])) % mod;
        }
    }
    cout << res << endl;
    return 0;
}