#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long comb(int n, int k) {
    if (k > n - k) k = n - k;
    long long res = 1;
    for (int i = 0; i < k; ++i) {
        res = res * (n - i) / (i + 1);
    }
    return res;
}

int main() {
    int k;
    cin >> k;
    vector<int> c(k);
    for (int i = 0; i < k; ++i) {
        cin >> c[i];
    }
    long long ans = 1;
    int sum = 0;
    for (int i = 0; i < k; ++i) {
        ans = ans * comb(sum + c[i] - 1, c[i] - 1) % MOD;
        sum += c[i];
    }
    cout << ans << endl;
    return 0;
}