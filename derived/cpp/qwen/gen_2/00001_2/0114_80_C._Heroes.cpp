#include <bits/stdc++.h>
using namespace std;

int n;
string heroes[] = {"Anka", "Chapay", "Cleo", "Dracul", "Hexadecimal", "Snowy", "Troll"};
map<string, int> hero_id;
map<int, vector<int>> likes;
long long a, b, c;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    for(int i=0;i<7;i++) hero_id[heroes[i]] = i;
    cin >> n;
    for(int i=0;i<n;i++){
        string p, q;
        cin >> p >> q >> q;
        likes[hero_id[p]].push_back(hero_id[q]);
    }
    cin >> a >> b >> c;
    int best_diff = 1e9;
    int best_like = -1;
    vector<vector<int>> best_teams;
    for(int i=0;i<(1<<7);i++){
        for(int j=0;j<(1<<7);j++){
            int k = (1<<7)-1-i-j;
            if(k == 0) continue;
            if((i & j) != 0 || (j & k) != 0 || (i & k) != 0) continue;
            int cnt1 = __builtin_popcount(i), cnt2 = __builtin_popcount(j), cnt3 = __builtin_popcount(k);
            long long x1 = a / cnt1, x2 = b / cnt2, x3 = c / cnt3;
            int mn = min({x1, x2, x3});
            int mx = max({x1, x2, x3});
            int cur_diff = mx - mn;
            int cur_like = 0;
            for(int l=0;l<7;l++){
                if(i & (1<<l)){
                    for(int q : likes[l]){
                        if(i & (1<<q)) cur_like++;
                    }
                }
                if(j & (1<<l)){
                    for(int q : likes[l]){
                        if(j & (1<<q)) cur_like++;
                    }
                }
                if(k & (1<<l)){
                    for(int q : likes[l]){
                        if(k & (1<<q)) cur_like++;
                    }
                }
            }
            if(cur_diff < best_diff || (cur_diff == best_diff && cur_like > best_like)){
                best_diff = cur_diff;
                best_like = cur_like;
                best_teams.clear();
                best_teams.push_back({});
                best_teams.push_back({});
                best_teams.push_back({});
                for(int l=0;l<7;l++){
                    if(i & (1<<l)) best_teams[0].push_back(l);
                    if(j & (1<<l)) best_teams[1].push_back(l);
                    if(k & (1<<l)) best_teams[2].push_back(l);
                }
            }
        }
    }
    cout << best_diff << " " << best_like << "\n";
    return 0;
}