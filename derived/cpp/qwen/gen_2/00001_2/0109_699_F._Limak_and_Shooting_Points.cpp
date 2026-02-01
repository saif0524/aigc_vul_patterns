#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    vector<pair<long long, long long>> stones(k);
    vector<pair<long long, long long>> monsters(n);
    
    for(auto &s: stones){
        cin >> s.first >> s.second;
    }
    
    for(auto &m: monsters){
        cin >> m.first >> m.second;
    }
    
    set<int> afraid_monsters;
    
    for(const auto &s: stones){
        for(int i = 0; i < n; ++i){
            const auto &[mx, my] = monsters[i];
            if(mx == s.first){
                bool can_hit = true;
                for(int j = 0; j < n; ++j){
                    if(i == j) continue;
                    const auto &[tx, ty] = monsters[j];
                    if(tx == s.first && ((my < s.second && ty > s.second) || (my > s.second && ty < s.second))){
                        can_hit = false;
                        break;
                    }
                }
                if(can_hit) afraid_monsters.insert(i);
            }
            else if(my == s.second){
                bool can_hit = true;
                for(int j = 0; j < n; ++j){
                    if(i == j) continue;
                    const auto &[tx, ty] = monsters[j];
                    if(ty == s.second && ((mx < s.first && tx > s.first) || (mx > s.first && tx < s.first))){
                        can_hit = false;
                        break;
                    }
                }
                if(can_hit) afraid_monsters.insert(i);
            }
            else{
                long double slope = (long double)(my - s.second) / (mx - s.first);
                long double intercept = s.second - slope * s.first;
                bool can_hit = true;
                for(int j = 0; j < n; ++j){
                    if(i == j) continue;
                    const auto &[tx, ty] = monsters[j];
                    long double y = slope * tx + intercept;
                    if(abs(y - ty) < 1e-9 && ((mx < s.first && tx > s.first) || (mx > s.first && tx < s.first))){
                        can_hit = false;
                        break;
                    }
                }
                if(can_hit) afraid_monsters.insert(i);
            }
        }
    }
    
    cout << afraid_monsters.size();
}