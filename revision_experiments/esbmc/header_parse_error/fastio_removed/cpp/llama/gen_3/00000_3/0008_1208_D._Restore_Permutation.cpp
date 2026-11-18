#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> s(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i].first;
        s[i].second = i;
    }
    vector<int> p(n);
    for (int i = n; i >= 1; --i) {
        int j = 0;
        while (j < n && s[j].first > 0) {
            ++j;
        }
        p[s[j].second] = i;
        for (int k = 0; k < n; ++k) {
            if (s[k].first >= i) {
                s[k].first -= i;
            }
        }
        s.erase(s.begin() + j);
    }
    for (int i = 0; i < n; ++i) {
        cout << p[i] << " ";
    }
    cout << endl;
}

int main() {
    ((void)0);
    ((void)0);
    solve();
    return 0;
}