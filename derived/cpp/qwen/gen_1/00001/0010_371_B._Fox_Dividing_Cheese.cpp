#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;
    if(a > b) swap(a, b);
    queue<pair<long long, int>> q;
    q.push({a, 0});
    set<long long> visited;
    visited.insert(a);
    while(!q.empty()){
        auto [current, steps] = q.front();
        q.pop();
        if(current == b){
            cout << steps;
            return 0;
        }
        if(current * 2 <= 1e9 && !visited.count(current * 2)){
            q.push({current * 2, steps + 1});
            visited.insert(current * 2);
        }
        if(current * 3 <= 1e9 && !visited.count(current * 3)){
            q.push({current * 3, steps + 1});
            visited.insert(current * 3);
        }
        if(current * 5 <= 1e9 && !visited.count(current * 5)){
            q.push({current * 5, steps + 1});
            visited.insert(current * 5);
        }
        if(current % 2 == 0 && !visited.count(current / 2)){
            q.push({current / 2, steps + 1});
            visited.insert(current / 2);
        }
        if(current % 3 == 0 && !visited.count(current * 3 / 2)){
            q.push({current * 3 / 2, steps + 1});
            visited.insert(current * 3 / 2);
        }
        if(current % 5 == 0 && !visited.count(current * 5 / 4)){
            q.push({current * 5 / 4, steps + 1});
            visited.insert(current * 5 / 4);
        }
    }
    cout << -1;
}