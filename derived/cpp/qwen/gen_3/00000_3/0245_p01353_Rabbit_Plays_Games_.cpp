#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Enemy {
    ll h, a, d, s;
};

bool compare(Enemy &e1, Enemy &e2) {
    return e1.s > e2.s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    Enemy hero, enemy[n];
    cin >> hero.h >> hero.a >> hero.d >> hero.s;
    for(int i=0;i<n;i++){
        cin >> enemy[i].h >> enemy[i].a >> enemy[i].d >> enemy[i].s;
    }
    sort(enemy, enemy+n, compare);
    ll total_damage = 0;
    bool hero_alive = true;
    priority_queue<pair<ll, int>> pq; // {-remaining_health, index}
    int j = 0;
    while(j < n || !pq.empty()){
        while(j < n && enemy[j].s >= hero.s){
            pq.push({-enemy[j].h, j});
            j++;
        }
        if(pq.empty()){
            hero_alive = false;
            break;
        }
        auto top = pq.top(); pq.pop();
        int index = top.second;
        ll damage = max(hero.a - enemy[index].d, 0LL);
        total_damage += damage;
        enemy[index].h -= damage;
        if(enemy[index].h > 0){
            pq.push({-enemy[index].h, index});
        }
        hero.h -= max(enemy[0].a - hero.d, 0LL);
        if(hero.h <= 0){
            hero_alive = false;
            break;
        }
    }
    if(hero_alive){
        while(!pq.empty()){
            auto top = pq.top(); pq.pop();
            ll damage = max(hero.a - enemy[top.second].d, 0LL);
            total_damage += damage;
            enemy[top.second].h -= damage;
            if(enemy[top.second].h <= 0){
                continue;
            }
            hero.h -= max(enemy[0].a - hero.d, 0LL);
            if(hero.h <= 0){
                hero_alive = false;
                break;
            }
        }
    }
    if(hero_alive){
        cout << total_damage;
    } else {
        cout << -1;
    }
}