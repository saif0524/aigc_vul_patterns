#include <bits/stdc++.h>
using namespace std;

int main(){
    int k, n;
    cin >> k >> n;
    vector<pair<long long, long long>> stones(k);
    vector<pair<long long, long long>> monsters(n);
    
    for(auto &s : stones) cin >> s.first >> s.second;
    for(auto &m : monsters) cin >> m.first >> m.second;
    
    set<int> afraid_monsters;
    
    for(int mask = 0; mask < (1 << k); mask++){
        for(auto &m : monsters){
            int index = -1;
            long long min_dist = LLONG_MAX;
            for(int i = 0; i < k; i++){
                if(mask & (1 << i)){
                    long long dx = abs(stones[i].first - m.first);
                    long long dy = abs(stones[i].second - m.second);
                    long long dist = dx + dy;
                    if(dist < min_dist){
                        min_dist = dist;
                        index = i;
                    }
                }
            }
            if(index != -1){
                bool visible = true;
                for(auto &other : monsters){
                    if(&other != &m){
                        long long dx1 = stones[index].first - m.first;
                        long long dy1 = stones[index].second - m.second;
                        long long dx2 = stones[index].first - other.first;
                        long long dy2 = stones[index].second - other.second;
                        if((dx1 * dy2 == dx2 * dy1) && (abs(dx1) + abs(dy1) > abs(dx2) + abs(dy2))){
                            visible = false;
                            break;
                        }
                    }
                }
                if(visible){
                    afraid_monsters.insert(m.first * 1000000009LL + m.second);
                }
            }
        }
    }
    
    cout << afraid_monsters.size();
}