#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
const int MAXQ = 100005;
const int MAXL = 100005;
const int MAXC = 26;

int n, q;
char s[MAXN];
struct Query {
    int type;
    int i, l, r;
    char c;
    string y;
};

Query queries[MAXQ];
int y_len[MAXQ];
int y_cnt[MAXQ];
vector<int> y_pos[MAXQ];
vector<int> lcp[MAXQ];

struct SuffixArray {
    int N;
    string S;
    int sa[MAXN], rank[MAXN], temp[MAXN], lcp[MAXN];

    void countingSort(int k) {
        int sum[MAXC + 1], maxi = max(300, N);
        memset(sum, 0, sizeof(sum));
        for (int i = 0; i < N; i++)
            sum[i + k < N ? rank[i + k] : 0]++;
        for (int i = 0, s = 0; i <= maxi; i++) {
            int t = sum[i];
            sum[i] = s;
            s += t;
        }
        for (int i = 0; i < N; i++)
            temp[sum[rank[i + k] < N ? rank[i + k] : 0]++] = i;
        for (int i = 0; i < N; i++)
            sa[i] = temp[i];
    }

    void buildSA(){
        N = (int)S.length();
        for (int i = 0; i < N; i++) rank[i] = S[i] - 'a', sa[i] = i;
        for (int k = 0; k < N; k ? k *= 2 : k++) {
            countingSort(k);
            countingSort(0);
            temp[sa[0]] = 1;
            for (int i = 1; i < N; i++)
                temp[sa[i]] = (rank[sa[i]] == rank[sa[i - 1]] && rank[sa[i] + k] == rank[sa[i - 1] + k]) ? temp[sa[i - 1]] : i + 1;
            for (int i = 0; i < N; i++)
                rank[i] = temp[i];
        }
        for (int i = 0; i < N; i++) rank[sa[i]] = i;

        int h = 0;
        lcp[0] = 0;
        for (int i = 0; i < N; i++) {
            if (rank[i] > 0) {
                int j = sa[rank[i] - 1];
                while (i + h < N && j + h < N && S[i + h] == S[j + h])
                    h++;
                lcp[rank[i]] = h;
                if (h > 0) h--;
            }
        }
    }

    pair<int, int> findOccurrence(const string & sub) {
        int lo = 0, hi = N - 1;
        while (lo < hi) {
            int mid = (lo + hi) >> 1;
            string prefix = S.substr(sa[mid], sub.size());
            
            if (prefix < sub)
                lo = mid + 1;
            else
                hi = mid;
        }
        string prefix = S.substr(sa[lo], sub.size());
        if (prefix != sub) return {-1, -1};
        pair<int, int> range = {lo, lo};
        for (int k = rank[lo] - 1; k >= 0 && lcp[k] >= (int)sub.size(); k--) range.first = sa[k];
        for (int k = rank[lo] + 1; k < N && lcp[k] >= (int)sub.size(); k++) range.second = sa[k];
        
        return range;
    }
};

SuffixArray sa;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin >> s;
    n = strlen(s);
    sa.S = s;
    sa.buildSA();
    
    cin >> q;
    for(int i=0; i<q; i++){
        cin >> queries[i].type;
        if(queries[i].type == 1){
            cin >> queries[i].i >> queries[i].c;
            queries[i].i--;
        }
        else{
            cin >> queries[i].l >> queries[i].r >> queries[i].y;
            queries[i].l--, queries[i].r--;
            
            int len = (int) queries[i].y.length();
            y_len[i] = len;
            if(len == 1){
                y_cnt[i] = 0;
                for(int j=queries[i].l; j<=queries[i].r; j++)
                    if(s[j] == queries[i].y[0]) y_cnt[i]++;
            }
            else{
                auto rng = sa.findOccurrence(queries[i].y);
                if(rng.first != -1){
                    for(int z=rng.first; z<=rng.second; z++){
                        int p = sa.sa[z];
                        if(p + len - 1 <= queries[i].r && p >= queries[i].l)
                            y_pos[i].push_back(p);
                    }
                    if(!y_pos[i].empty())
                        sort(y_pos[i].begin(), y_pos[i].end());
                }
                
                int m = (int) y_pos[i].size();
                if(m > 1){
                    for(int j=1; j<m; j++)
                        lcp[j] = 0;
                    if(m > 1){
                        int h = 0;
                        for(int j=1; j<m; j++){
                            int len = min(n - y_pos[i][j-1], n - y_pos[i][j]);
                            while(h < len && sa.S[y_pos[i][j-1] + h] == sa.S[y_pos[i][j] + h])
                                h++;
                            lcp[j] = h;
                            if(h > 0) h--;
                        }
                    }
                }
            }
        }
    }
    
    for(int i=0, j=0; i<q; i++){
        if(queries[i].type == 1){
            s[queries[i].i] = queries[i].c;
            
            for(j; j<i; j++){
                if(queries[j].type == 2 && y_len[j] > 1){
                    vector<int> & occ = y_pos[j];
                    int idx = lower_bound(occ.begin(), occ.end(), queries[i].i) - occ.begin();
                    
                    if(!occ.empty()){
                        if(occ.back() == queries[i].i)
                            occ.pop_back();
                        else if(idx > 0 && occ[idx] == queries[i].i)
                            occ.erase(occ.begin() + idx);
                    }
                    
                    if(!occ.empty()){
                        if(queries[j].l < queries[i].i && queries[i].i <= queries[j].r){
                            for(int k=1; k<occ.size(); k++){
                                if(lcp[k] > idx){
                                    occ[k]--;
                                    lcp[k] -= idx;
                                }
                                else if(lcp[k] == idx){
                                    occ.erase(occ.begin() + k);
                                    lcp.erase(lcp.begin() + k);
                                    k--;
                                }
                            }
                        }
                    }
                }
            }
        }
        else{
            if(y_len[i] == 1) cout << y_cnt[i] << "\n";
            else cout << (int) y_pos[i].size() << "\n";
        }
    }
}