#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, p;
    cin >> n >> p;
    string s;
    cin >> s;
    vector<vector<int>> A(p, vector<int>(p));
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            cin >> A[i][j];
        }
    }
    vector<int> freq(p, 0);
    for(char c : s){
        freq[c - 'a']++;
    }
    vector<bool> valid(p, true);
    int ans = n;
    for(int mask=1;mask<(1<<p);mask++){
        vector<bool> can_connect(p, false);
        vector<int> selected;
        int cnt = 0;
        for(int i=0;i<p;i++){
            if(mask & (1<<i)){
                cnt++;
                selected.push_back(i);
                if(freq[i] == 0){
                    can_connect[i] = true;
                    continue;
                }
            }
        }
        if(cnt == 0){
            continue;
        }
        can_connect[selected[0]] = true;
        bool ok = true;
        for(int i=1;i<cnt;i++){
            bool found = false;
            for(int j=0;j<i;j++){
                if(A[selected[i]][selected[j]] || A[selected[j]][selected[i]]){
                    can_connect[selected[i]] = true;
                    found = true;
                    break;
                }
            }
            if(!found){
                ok = false;
                break;
            }
        }
        if(!ok){
            continue;
        }
        int current_length = 0;
        for(int i=0;i<p;i++){
            if(can_connect[i]){
                current_length += freq[i];
            }
        }
        ans = min(ans, current_length);
    }
    cout << ans;
}