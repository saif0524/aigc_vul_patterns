#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    string S, T;
    int q;
    cin >> S >> T >> q;
    
    int n = S.size();
    int m = T.size();
    
    vector<vector<int>> freq_S(n+1, vector<int>(26, 0));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 26; j++) freq_S[i+1][j] = freq_S[i][j];
        freq_S[i+1][S[i]-'a']++;
    }
    
    vector<vector<int>> freq_T(m, vector<int>(26, 0));
    for(int i = 0; i < m; i++){
        freq_T[i][T[i]-'a']++;
    }
    
    auto getfreq_S = [&](int l, int r){
        vector<int> res(26, 0);
        for(int i = 0; i < 26; i++) res[i] = freq_S[r+1][i] - freq_S[l][i];
        return res;
    };
    
    auto getfreq_T = [&](int l, int r){
        vector<int> res(26, 0);
        for(int i = 0; i < 26; i++) res[i] = freq_T[r][i] - (l > 0 ? freq_T[l-1][i] : 0);
        return res;
    };
    
    auto compare = [&](int l, vector<int> &pref_S, vector<int> &pref_T, vector<int> &suf_S, vector<int> &suf_T){
        vector<int> left(26, 0);
        for(int i = 0; i < 26; i++) left[i] = pref_S[i] + pref_T[i];
        vector<int> right(26, 0);
        for(int i = 0; i < 26; i++) right[i] = suf_S[i] + suf_T[i];
        for(int i = 0; i < 26; i++){
            if(left[i] < right[i]) return false;
            if(left[i] > right[i]) return true;
        }
        return l < n;
    };
    
    while(q--){
        int l, r, k, x, y;
        cin >> l >> r >> k >> x >> y;
        
        vector<int> pref_S = getfreq_S(0, l-1);
        vector<int> pref_T = getfreq_T(x, y);
        vector<int> suf_S = getfreq_S(r, n-1);
        vector<int> suf_T = getfreq_T(k-y-1, k-x-1);
        
        int ans = -1;
        for(int i = l; i <= r; i++){
            if(compare(i, pref_S, pref_T, suf_S, suf_T)){
                ans = i;
                break;
            }
            pref_S[S[i]-'a']++;
            suf_S[S[i]-'a']--;
        }
        
        cout << ans << "\n";
    }
}