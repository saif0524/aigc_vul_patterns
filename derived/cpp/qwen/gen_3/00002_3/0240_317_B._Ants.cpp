#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    map<pair<long long, long long>, int> ants;
    ants[{0, 0}] = n;
    bool changed = true;
    while(changed){
        changed = false;
        map<pair<long long, long long>, int> new_ants = ants;
        for(auto &p : ants){
            long long x = p.first.first;
            long long y = p.first.second;
            int cnt = p.second;
            if(cnt >= 4){
                int scatter = cnt / 4;
                new_ants[{x, y}] -= scatter * 4;
                new_ants[{x+1, y}] += scatter;
                new_ants[{x-1, y}] += scatter;
                new_ants[{x, y+1}] += scatter;
                new_ants[{x, y-1}] += scatter;
                changed = true;
            }
        }
        ants = new_ants;
    }
    while(t--){
        long long xi, yi;
        cin >> xi >> yi;
        cout << ants[{xi, yi}] << "\n";
    }
}