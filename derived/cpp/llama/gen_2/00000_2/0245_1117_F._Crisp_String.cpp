#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

int n, p;
string s;
vector<vector<int>> A;
vector<int> cnt(17);
bitset<17> ban;

void dfs(int i, int len) {
    if (len < n) {
        n = len;
    }
    if (i == p) {
        return;
    }
    int c = 0;
    for (int j = 0; j < p; j++) {
        if (!ban[j] && !A[i][j] && cnt[j] > 0) {
            ban[j] = 1;
            c = 1;
            break;
        }
    }
    if (c) {
        cnt[i] = 0;
        for (int j = 0; j < s.size(); j++) {
            if (s[j] - 'a' == i) {
                s.erase(j, 1);
                j--;
            }
        }
        dfs(0, s.size());
    } else {
        dfs(i + 1, len);
    }
    if (c) {
        s = "";
        for (int j = 0; j < n; j++) {
            if (cnt[j] > 0) {
                s += (char)(j + 'a');
            }
        }
        ban.reset();
        for (int j = 0; j < p; j++) {
            if (A[i][j] && cnt[i] > 0 && cnt[j] > 0) {
                ban[j] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> p;
    cin >> s;
    A.resize(p, vector<int>(p));
    for (int i = 0; i < p; i++) {
        for (int j = 0; j < p; j++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    dfs(0, n);
    cout << n << endl;
    return 0;
}