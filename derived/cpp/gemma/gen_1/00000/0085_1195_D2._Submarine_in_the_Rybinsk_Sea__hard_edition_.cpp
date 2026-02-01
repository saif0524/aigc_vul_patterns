#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

string f(long long x, long long y) {
    string sx = to_string(x);
    string sy = to_string(y);
    int p = sx.length();
    int q = sy.length();
    string result = "";
    int i = p - 1;
    int j = q - 1;
    while (i >= 0 || j >= 0) {
        if (i >= 0) {
            result += sx[i];
            i--;
        }
        if (j >= 0) {
            result += sy[j];
            j--;
        }
    }
    reverse(result.begin(), result.end());
    return result;
}

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            string combined = f(a[i], a[j]);
            long long num = 0;
            for (char c : combined) {
                num = (num * 10 + (c - '0')) % MOD;
            }
            sum = (sum + num) % MOD;
        }
    }

    cout << sum << endl;

    return 0;
}