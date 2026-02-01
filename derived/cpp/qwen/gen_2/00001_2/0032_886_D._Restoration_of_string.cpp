#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    vector<int> sa, rank, lcp;
    string s;
    int n;

    SuffixArray(string &s) : s(s), n(s.size()) {
        sa.resize(n);
        rank.resize(n);
        lcp.resize(n - 1);

        for (int i = 0; i < n; i++) sa[i] = i;
        sort(sa.begin(), sa.end(), [&](int x, int y) { return s[x] < s[y]; });

        for (int i = 0, r = 0; i < n; i++) {
            if (i > 0 && s[sa[i]] != s[sa[i - 1]]) r++;
            rank[sa[i]] = r;
        }

        vector<int> tmp(n);
        for (int step = 1; step < n; step <<= 1) {
            auto cmp = [&](int x, int y) {
                int fx = rank[x], fy = rank[y];
                int sx = x + step < n ? rank[x + step] : -1;
                int sy = y + step < n ? rank[y + step] : -1;
                return make_pair(fx, sx) < make_pair(fy, sy);
            };
            sort(sa.begin(), sa.end(), cmp);
            for (int i = 0, r = 0; i < n; i++) {
                if (i > 0 && cmp(sa[i - 1], sa[i])) r++;
                tmp[sa[i]] = r;
            }
            swap(rank, tmp);
        }

        for (int i = 0, k = 0; i < n; i++) {
            if (rank[i] == n - 1) {
                k = 0;
                continue;
            }
            int j = sa[rank[i] + 1];
            while (i + k < n && j + k < n && s[i + k] == s[j + k]) k++;
            lcp[rank[i]] = k;
            if (k) k--;
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<string> v(n);
    for(auto &s: v) cin >> s;
    string combined = "";
    for(auto &s: v) combined += s + '#';
    combined.pop_back();
    SuffixArray sa(combined);
    vector<int> cnt(combined.size());
    for(auto &s: v){
        int l = 0, r = combined.size() - s.size();
        while(l < r){
            int m = (l+r)/2;
            string cur = combined.substr(sa.sa[m], s.size());
            if(cur < s) l = m+1;
            else r = m;
        }
        if(combined.substr(sa.sa[l], s.size()) == s){
            int pos = l;
            while(pos < sa.n && combined.substr(sa.sa[pos], s.size()) == s){
                cnt[sa.sa[pos]]++;
                pos++;
            }
        }
    }
    vector<string> parts;
    for(int i=0;i<combined.size();i++) if(cnt[i] == n){
        int len = i == 0 ? sa.lcp[0] : sa.lcp[i-1] + 1; 
        parts.push_back(combined.substr(sa.sa[i], len));
    }
    if(parts.empty()){
        cout << "NO";
    } else {
        sort(parts.begin(), parts.end());
        cout << parts[0];
    }
}