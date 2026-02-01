#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <bitset>

using namespace std;

int mod = 998244353;
int n, m;

vector<string> words;
vector<string> rev_words;

map<string, int> word_map;
map<string, int> rev_word_map;

int num_chains;

void add_to_map(vector<string>& words, map<string, int>& word_map) {
    for (int i = 0; i < words.size(); i++) {
        word_map[words[i]] = i;
    }
}

void dfs(int pos, int mask, int rev_mask) {
    if (pos >= m) {
        num_chains++;
        return;
    }
    for (int i = 0; i < words.size(); i++) {
        if (!(mask & (1 << i))) {
            string word = words[i];
            if (pos + word.size() <= m) {
                dfs(pos + word.size(), mask | (1 << i), rev_mask);
            }
        }
    }
    for (int i = 0; i < rev_words.size(); i++) {
        if (!(rev_mask & (1 << i))) {
            string word = rev_words[i];
            if (pos + word.size() <= m) {
                dfs(pos + word.size(), mask, rev_mask | (1 << i));
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    words.resize(n);
    rev_words.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> words[i];
        rev_words[i] = words[i];
        reverse(rev_words[i].begin(), rev_words[i].end());
    }

    add_to_map(words, word_map);
    add_to_map(rev_words, rev_word_map);

    vector<vector<int>> dp(m + 1, vector<int>(n, 0));
    vector<vector<int>> rev_dp(m + 1, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        string word = words[i];
        if (word.size() <= m) {
            dp[word.size()][i] = 1;
        }
    }

    for (int i = 0; i < n; i++) {
        string word = rev_words[i];
        if (word.size() <= m) {
            rev_dp[word.size()][i] = 1;
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            string word = words[j];
            if (i >= word.size()) {
                int prev = dp[i - word.size()][j];
                dp[i][j] += prev;
                dp[i][j] %= mod;
            }
        }
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < n; j++) {
            string word = rev_words[j];
            if (i >= word.size()) {
                int prev = rev_dp[i - word.size()][j];
                rev_dp[i][j] += prev;
                rev_dp[i][j] %= mod;
            }
        }
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ans += (long long)dp[m][i] * rev_dp[m][j];
            ans %= mod;
        }
    }

    cout << ans << '\n';

    return 0;
}