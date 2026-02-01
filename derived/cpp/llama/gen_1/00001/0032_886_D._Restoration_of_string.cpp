#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int N = 200;
vector<int> g[N];
bool used[N];
bool good = true;

void dfs(int v) {
    used[v] = true;
    for (int to : g[v]) {
        if (used[to]) {
            good = false;
            return;
        }
        dfs(to);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), [](const string& s1, const string& s2) {
        int lcp = 0;
        while (lcp < min(s1.size(), s2.size()) && s1[lcp] == s2[lcp]) {
            lcp++;
        }
        if (lcp < s1.size() && lcp < s2.size()) {
            if (s1[lcp] < s2[lcp]) {
                return true;
            } else {
                return false;
            }
        }
        return s1.size() < s2.size();
    });
    vector<string> b(n);
    b[0] = a[0];
    for (int i = 1; i < n; i++) {
        int lcp = 0;
        while (lcp < min(b[i - 1].size(), a[i].size()) && b[i - 1][b[i - 1].size() - lcp - 1] == a[i][lcp]) {
            lcp++;
        }
        if (lcp == a[i].size()) {
            if (lcp == b[i - 1].size()) {
                b[i] = a[i];
            } else {
                b[i] = b[i - 1];
            }
        } else if (lcp == b[i - 1].size()) {
            b[i] = b[i - 1] + a[i].substr(lcp);
        } else {
            good = false;
            break;
        }
    }
    if (!good) {
        cout << "NO";
    } else {
        cout << b[n - 1];
    }
    return 0;
}