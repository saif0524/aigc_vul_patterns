#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    map<string, int> id;
    string names[] = {"Anka", "Chapay", "Cleo", "Troll", "Dracul", "Snowy", "Hexadecimal"};
    for(int i=0; i<7; ++i) id[names[i]] = i;
    
    int n;
    cin >> n;
    vector<int> adj[7];
    for(int i=0; i<n; ++i){
        string p, q, s;
        cin >> p >> s >> q;
        adj[id[p]].push_back(id[q]);
    }
    
    long long a, b, c;
    cin >> a >> b >> c;
    
    long long res_diff = LLONG_MAX;
    int res_like = -1;
    string best_teams;
    
    for(int m1=0; m1<(1<<7); ++m1){
        for(int m2=0; m2<(1<<7); ++m2){
            if(m1&m2) continue;
            int m3 = ((1<<7)-1) ^ m1 ^ m2;
            if(m3==0) continue;
            
            long long exp1 = 0, exp2 = 0, exp3 = 0;
            int cnt1 = 0, cnt2 = 0, cnt3 = 0;
            int like1 = 0, like2 = 0, like3 = 0;
            
            for(int i=0; i<7; ++i){
                if(m1&(1<<i)){
                    exp1 += a;
                    cnt1++;
                    for(int j: adj[i]) if(m1&(1<<j)) like1++;
                }
                else if(m2&(1<<i)){
                    exp2 += b;
                    cnt2++;
                    for(int j: adj[i]) if(m2&(1<<j)) like2++;
                }
                else{
                    exp3 += c;
                    cnt3++;
                    for(int j: adj[i]) if(m3&(1<<j)) like3++;
                }
            }
            
            exp1 /= cnt1; exp2 /= cnt2; exp3 /= cnt3;
            
            long long diff = max({exp1, exp2, exp3}) - min({exp1, exp2, exp3});
            int like = like1 + like2 + like3;
            
            if(diff < res_diff || (diff == res_diff && like > res_like)){
                res_diff = diff;
                res_like = like;
                best_teams = to_string(m1) + " " + to_string(m2) + " " + to_string(m3);
            }
        }
    }
    
    cout << res_diff << " " << res_like;
}