#include <bits/stdc++.h>
using namespace std;

struct SuffixArray {
    string s;
    int n;
    vector<int> sa, tmp, ra, tmp_ra, lcp;

    void build_sa() {
        int i, k, r;
        n = (int)s.length();
        sa.resize(n);
        tmp.resize(n);
        ra.resize(n);
        tmp_ra.resize(n);
        for(i = 0; i < n; i++) sa[i] = i, ra[i] = s[i];
        for(k = 1; k < n; k <<= 1) {
            tmp_ra[sa[0]] = r = 0;
            for(i = 1; i < n; i++) 
                tmp_ra[sa[i]] = (ra[sa[i]] == ra[sa[i-1]] && ra[sa[i] + k] == ra[sa[i-1] + k]) ? r : ++r;
            for(copy(tmp_ra.begin(), tmp_ra.end(), ra.begin()), i = 0; i < n; i++) tmp[ra[sa[i]]] = i;
            for(i = 0; i < n; i++) if(tmp[i] > 0) {
                for(j = sa[tmp[i] - 1], k = max(0, k-1); s[i+k] == s[j+k]; k++);
                lcp[tmp[i]] = k;
            } else k = 0;
        }
    }

    void build_lcp() {
        int i, k, r;
        n = (int)s.length();
        lcp.resize(n);
        lcp[0] = k = 0;
        for(i = 1; i < n; i++) 
            if(ra[sa[i]] != ra[sa[i-1]]) lcp[ra[sa[i]]] = k = max(0, k-1);
            else {
                for(j = sa[ra[sa[i]] - 1], k = max(0, k-1); s[i+k] == s[j+k]; k++);
                lcp[ra[sa[i]]] = k;
            }
    }

    pair<int, int> lcp_range_query(int L, int R) {
        if(L == R) return make_pair(n - sa[L], sa[L]);
        L = ra[L], R = ra[R];
        if(L > R) swap(L, R);
        L++, R--;
        int j = 31 - __builtin_clz(R - L + 1), k = log2_j[j];
        int mn = min(sp[L][k], sp[R - (1 << k) + 1][k]);
        return make_pair(mn, sa[sp[L][k] == mn ? L : (R - (1 << k) + 1)]);
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    string S;
    cin >> S;
    int m;
    cin >> m;
    vector<pair<string, string>> queries(m);
    vector<int> starts, ends;
    map<string, vector<int>> start_idx, end_idx;
    for(int i = 0; i < m; i++){
        cin >> queries[i].first >> queries[i].second;
        starts.push_back(S.find(queries[i].first));
        ends.push_back(S.rfind(queries[i].second));
        start_idx[queries[i].first].push_back(i);
        end_idx[queries[i].second].push_back(i);
    }
    SuffixArray sa;
    sa.s = S;
    sa.build_sa();
    sa.build_lcp();
    vector<int> ans(m, 0);
    for(auto &p : start_idx){
        string s1 = p.first;
        vector<int> ids = p.second;
        int L = -1, R = -1;
        for(int s : ids){
            if(starts[s] == -1) continue;
            if(L == -1){
                L = starts[s];
                R = starts[s];
            } else {
                if(starts[s] < L) L = starts[s];
                if(starts[s] > R) R = starts[s];
            }
        }
        if(L == -1 || R == -1) continue;
        int mn = 2e9, idx = -1;
        for(auto &p2 : end_idx){
            string s2 = p2.first;
            vector<int> ids2 = p2.second;
            for(int s : ids2){
                if(ends[s] == -1) continue;
                if(ends[s] < L + (int)s1.length() - 1) continue;
                pair<int, int> res = sa.lcp_range_query(L, ends[s]);
                if(res.first > (int)s1.length() - 1) continue;
                if(res.first > mn) continue;
                if(res.first < mn){
                    mn = res.first;
                    idx = res.second;
                } else {
                    idx = min(idx, res.second);
                }
            }
        }
        if(idx == -1) continue;
        for(int s : ids){
            if(starts[s] == -1) continue;
            int l = (int)s1.length() - 1 + sa.lcp_range_query(starts[s], idx).first;
            if(S[starts[s] + l] == S[ends[s]]) ans[s] = max(ans[s], ends[s] - starts[s] + 1);
        }
    }
    for(int i = 0; i < m; i++){
        cout << ans[i] << "\n";
    }
}