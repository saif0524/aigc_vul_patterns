#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int N;
    cin >> N;

    unordered_map<string, int> S;
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        S[s] = 1;
    }

    string t;
    cin >> t;
    int n = t.size();

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            string s = t.substr(j, i - j);
            if (S.count(s)) {
                dp[i] = (dp[i] + dp[j]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}