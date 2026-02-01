#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(string s) {
    int n = s.size();
    vector<int> z(n);
    for (int i = 1, l = 0, r = 0; i < n; ++i) {
        if (i <= r) z[i] = min(r - i + 1, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) ++z[i];
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

long long self_similarity(const string& s) {
    long long total = 0;
    int n = s.size();
    // Count occurrences of each prefix
    for (int len = 1; len <= n; ++len) {
        string t = s.substr(0, len);
        string combined = t + "#" + s;
        auto z = z_function(combined);
        int count = 0;
        for (int i = len + 1; i < combined.size(); ++i) {
            if (z[i] >= len) ++count;
        }
        total += count * len;
    }
    return total;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        cout << self_similarity(s) << "\n";
    }
}