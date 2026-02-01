#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int f(string a, string b) {
    int result = 0;
    int p = a.size();
    int q = b.size();
    int i = 0;
    int j = 0;

    while (j < q || i < p) {
        if (j < q) {
            result = (result * 10 + b[q - j - 1] - '0') % MOD;
            j++;
        }
        if (i < p) {
            result = (result * 10 + a[p - i - 1] - '0') % MOD;
            i++;
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long result = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result = (result + f(a[i], a[j])) % MOD;
        }
    }

    cout << result << endl;

    return 0;
}