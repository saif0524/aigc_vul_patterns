#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l, k;
    cin >> n >> l >> k;

    string s;
    cin >> s;

    sort(s.begin(), s.end());

    vector<string> words(n);
    int start = 0;
    int end = k - 1;
    int idx = 0;

    for (int i = 0; i < l; ++i) {
        for (int j = start; j <= end; ++j) {
            words[j].push_back(s[idx]);
            idx++;
        }

        if (end < n - 1) {
            int diff = end - start + 1;
            start = end + 1;
            end = start + diff - 1;
        }
    }

    for (int i = 0; i < n; ++i) {
        while (words[i].size() < l) {
            words[i].push_back(s[idx]);
            idx++;
        }
        cout << words[i] << "\n";
    }

    return 0;
}