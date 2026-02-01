#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXP = 17;

int n, p;
char s[MAXN];
int A[MAXP][MAXP];

bool isCrisp(string& t, int toRemove) {
    for (int i = 0; i < t.size() - 1; ++i) {
        int c1 = t[i] - 'a';
        int c2 = t[i + 1] - 'a';
        if (c1 != toRemove && c2 != toRemove && A[c1][c2] == 0) {
            return false;
        }
    }
    return true;
}

string removeChar(string& t, int toRemove) {
    string res = "";
    for (char c : t) {
        if (c - 'a' != toRemove) {
            res += c;
        }
    }
    return res;
}

int bruteForce(string t, int mask, vector<int>& available) {
    if (mask == (1 << p) - 1) {
        return t.size();
    }

    int best = t.size();
    for (int i = 0; i < p; ++i) {
        if ((mask & (1 << i)) == 0 && available[i]) {
            string nt = removeChar(t, i);
            if (isCrisp(nt, -1)) {
                best = min(best, bruteForce(nt, mask | (1 << i), available));
            }
        }
    }
    return best;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> p;
    cin >> s;

    for (int i = 0; i < p; ++i) {
        for (int j = 0; j < p; ++j) {
            cin >> A[i][j];
        }
    }

    vector<int> available(p, 0);
    for (int i = 0; i < n; ++i) {
        available[s[i] - 'a'] = 1;
    }

    string t = s;
    cout << bruteForce(t, 0, available) << endl;

    return 0;
}