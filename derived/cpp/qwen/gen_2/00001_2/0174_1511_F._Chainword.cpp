#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int MAX_N = 8;
const int MAX_M = 1005;

int n, m;
vector<string> words;
vector<int> lengths;
int memo1[MAX_M][1<<MAX_N];
int memo2[MAX_M][1<<MAX_N];

int count_ways(int pos, int mask, vector<int>& memo) {
    if (pos == m) return 1;
    if (memo[pos][mask] != -1) return memo[pos][mask];
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (!(mask & (1 << i)) && pos + lengths[i] <= m) {
            ans = (ans + count_ways(pos + lengths[i], mask | (1 << i), memo)) % MOD;
        }
    }
    memo[pos][mask] = ans;
    return ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m;
    words.resize(n);
    lengths.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> words[i];
        lengths[i] = words[i].size();
    }
    memset(memo1, -1, sizeof(memo1));
    memset(memo2, -1, sizeof(memo2));
    long long ans = 0;
    for (int i = 0; i < (1 << n); ++i) {
        int ways1 = count_ways(0, i, memo1);
        int ways2 = count_ways(0, i, memo2);
        ans = (ans + 1LL * ways1 * ways2) % MOD;
    }
    cout << ans << "\n";
    return 0;
}