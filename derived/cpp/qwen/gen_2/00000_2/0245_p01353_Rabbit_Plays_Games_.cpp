#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<array<long long, 4>> enemies(n);
    for(auto &e: enemies){
        cin >> e[0] >> e[1] >> e[2] >> e[3];
    }
    long long hero_h, hero_a, hero_d, hero_s;
    cin >> hero_h >> hero_a >> hero_d >> hero_s;
    sort(enemies.begin(), enemies.end(), [](const auto &a, const auto &b){
        return a[3] > b[3];
    });
    priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<>> pq;
    long long total_damage = 0;
    int killed = 0;
    for(int i = 0; i < n || !pq.empty();){
        while(i < n && enemies[i][3] >= hero_s){
            pq.emplace(enemies[i][1] - hero_d, enemies[i][0]);
            i++;
        }
        long long hero_dmg = hero_a;
        if(!pq.empty()){
            auto [enemy_dmg, enemy_hp] = pq.top();
            pq.pop();
            if(enemy_dmg > 0){
                hero_dmg -= enemy_dmg;
                if(hero_dmg <= 0){
                    cout << -1;
                    return 0;
                }
            }
            enemy_hp -= hero_dmg;
            total_damage += hero_dmg;
            if(enemy_hp > 0){
                pq.emplace(enemy_dmg, enemy_hp);
            } else {
                killed++;
            }
        } else {
            cout << -1;
            return 0;
        }
    }
    cout << total_damage;
}