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
        for(auto it : ants){
            long long x = it.first.first, y = it.first.second;
            int cnt = it.second;
            if(cnt >= 4){
                new_ants[{x, y}] -= cnt / 4 * 4;
                new_ants[{x + 1, y}] += cnt / 4;
                new_ants[{x - 1, y}] += cnt / 4;
                new_ants[{x, y + 1}] += cnt / 4;
                new_ants[{x, y - 1}] += cnt / 4;
                changed = true;
            }
        }
        ants = new_ants;
    }
    for(int i=0; i<t; i++){
        long long xi, yi;
        cin >> xi >> yi;
        cout << ants[{xi, yi}] << "\n";
    }
}