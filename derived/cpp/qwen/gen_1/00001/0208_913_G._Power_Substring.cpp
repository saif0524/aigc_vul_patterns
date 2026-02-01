#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

const int MOD = 1000000000 + 7;

long long power_mod(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1)
            result = result * base % mod;
        exp >>= 1;
        base = base * base % mod;
    }
    return result;
}

int find_ki(const string& ai) {
    int len = ai.size();
    long long mod = 1;
    for (int i = 0; i < len; ++i)
        mod *= 10;

    long long hashes[100001] = {0};
    long long pows[100001] = {0};
    pows[0] = 1;
    for (int i = 1; i <= 100000; ++i) {
        pows[i] = pows[i-1] * 2 % mod;
        hashes[i] = (hashes[i-1] * 2 + ((power_mod(2, i, 10) - 1) % 10)) % mod;
        if (i >= len) {
            long long h = hashes[i];
            for (int j = i; j >= len; --j) {
                string sub = to_string(power_mod(2, j, mod));
                if (sub.size() >= len) {
                    string last = sub.substr(sub.size() - len);
                    if (last == ai) {
                        return j;
                    }
                }
                h = (h - pows[len] * ((power_mod(2, j - len, 10) - 1) % 10) % mod + mod) % mod;
            }
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        string ai;
        cin >> ai;
        int ki = find_ki(ai);
        cout << ki << "\n";
    }
    return 0;
}