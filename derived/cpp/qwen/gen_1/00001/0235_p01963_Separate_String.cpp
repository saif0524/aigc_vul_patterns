#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct Node {
    int cnt;
    Node* child[26];
    Node() : cnt(0) {
        memset(child, 0, sizeof(child));
    }
};

void insert(Node* root, const string& s) {
    Node* curr = root;
    for (char c : s) {
        if (!curr->child[c - 'a']) {
            curr->child[c - 'a'] = new Node();
        }
        curr = curr->child[c - 'a'];
    }
    curr->cnt++;
}

long long dp[100005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    Node* root = new Node();
    for (int i = 0; i < N; ++i) {
        string s;
        cin >> s;
        insert(root, s);
    }
    string t;
    cin >> t;
    int n = t.size();
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = 0;
        Node* curr = root;
        for (int j = i; j > 0; --j) {
            char c = t[j - 1];
            if (!curr->child[c - 'a']) break;
            curr = curr->child[c - 'a'];
            if (curr->cnt > 0) {
                dp[i] = (dp[i] + dp[j - 1]) % MOD;
            }
        }
    }
    cout << dp[n] << "\n";
}