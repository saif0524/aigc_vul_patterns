#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 5;

int cnt[26], need_b[26], need_c[26];

bool can_form(string &s, int len) {
    for (int i = 0; i < 26; ++i) cnt[i] = 0;
    for (int i = 0; i < len; ++i) cnt[s[i] - 'a']++;
    for (int i = 0; i < 26; ++i) {
        if (cnt[i] < need_b[i] && cnt[i] < need_c[i]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string a, b, c;
    cin >> a >> b >> c;
    
    int n = a.size();
    int nb = b.size();
    int nc = c.size();
    
    for (int i = 0; i < nb; ++i) need_b[b[i] - 'a']++;
    for (int i = 0; i < nc; ++i) need_c[c[i] - 'a']++;
    
    vector<int> order;
    for (int i = 0; i < 26; ++i) {
        if (need_b[i] >0 || need_c[i] > 0) {
            order.push_back(i);
        }
    }
    
    sort(order.begin(), order.end(), [&](int x, int y) {
        return need_b[x] + need_c[x] > need_b[y] + need_c[y];
    });
    
    string result;
    int ptr = 0;
    while (ptr < n) {
        bool found = false;
        for (int i = 0; i < order.size(); ++i) {
            int ch = order[i];
            if (can_form(a.substr(ptr, min(nb, nc)), nb) && need_b[ch] > 0) {
                for (int j = 0; j < nb; ++j) cnt[a[ptr + j] - 'a']--;
                result += b;
                ptr += nb;
                need_b[ch]--;
                found = true;
                break;
            }
            if (can_form(a.substr(ptr, min(nb, nc)), nc) && need_c[ch] > 0) {
                for (int j = 0; j < nc; ++j) cnt[a[ptr + j] - 'a']--;
                result += c;
                ptr += nc;
                need_c[ch]--;
                found = true;
                break;
            }
        }
        if (!found) {
            result += a[ptr++];
        }
    }
    
    cout << result << "\n";
    
    return 0;
}