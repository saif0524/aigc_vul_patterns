#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

const int MOD = 998244353;

long long power(long long a, long long b, long long mod = MOD) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<string> words(n);
    unordered_map<string, int> wordToIndex;
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        wordToIndex[words[i]] = i;
    }

    int dpSize = 1 << (n * 3);
    vector<long long> dp(dpSize);
    dp[0] = 1;

    for (int i = 1; i <= m; i++) {
        vector<long long> nextDp(dpSize);
        for (int j = 0; j < dpSize; j++) {
            for (int k = 0; k < n; k++) {
                string word = words[k];
                int mask = ((1 << (3 * k)) | (1 << (3 * k + 1)) | (1 << (3 * k + 2)));
                if ((j & mask) == 0 && i >= word.size()) {
                    int nextMask = j;
                    for (int l = i - word.size(); l <= i; l++) {
                        for (int p = 0; p < n; p++) {
                            string nextWord = words[p];
                            if (l >= nextWord.size() && word[l - nextWord.size()] == nextWord[nextWord.size() - 1]) {
                                nextMask |= (1 << (3 * p));
                            }
                        }
                    }
                    nextDp[nextMask] = (nextDp[nextMask] + dp[j]) % MOD;
                }
            }
        }
        dp = nextDp;
    }

    long long ans = 0;
    for (long long x : dp) {
        ans = (ans + x) % MOD;
    }

    cout << ans << endl;

    return 0;
}