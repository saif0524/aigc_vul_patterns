#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

struct TrieNode {
    TrieNode* children[26];
    int index;
    TrieNode() : index(-1) {
        memset(children, 0, sizeof(children));
    }
};

void insert(TrieNode* root, const string& s, int idx) {
    TrieNode* node = root;
    for (char c : s) {
        if (!node->children[c - 'a']) {
            node->children[c - 'a'] = new TrieNode();
        }
        node = node->children[c - 'a'];
    }
    node->index = idx;
}

vector<int> findPrefixes(const string& t, TrieNode* root) {
    vector<int> result;
    int n = t.size();
    for (int i = 0; i < n; ++i) {
        TrieNode* node = root;
        for (int j = i; j < n; ++j) {
            char c = t[j];
            if (node->children[c - 'a']) {
                node = node->children[c - 'a'];
                if (node->index != -1) {
                    result.push_back(node->index);
                }
            } else {
                break;
            }
        }
    }
    return result;
}

int main() {
    int N;
    cin >> N;
    vector<string> S(N);
    TrieNode* root = new TrieNode();
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
        insert(root, S[i], i);
    }
    string t;
    cin >> t;
    vector<int> prefixes = findPrefixes(t, root);
    int m = t.size();
    vector<long long> dp(m + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < prefixes.size(); ++j) {
            if (i + 1 >= S[prefixes[j]].size()) {
                int k = i + 1 - S[prefixes[j]].size();
                if (t.substr(k, S[prefixes[j]].size()) == S[prefixes[j]]) {
                    dp[i + 1] = (dp[i + 1] + dp[k]) % MOD;
                }
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}