#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> edges(m);
    for(auto &e: edges){
        cin >> e.first >> e.second;
    }
    long long sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            bool found = false;
            for(auto &e: edges){
                if((e.first == i && e.second == j) || (e.first == j && e.second == i)){
                    found = true;
                    break;
                }
            }
            if(!found){
                sum += i * j;
            }
        }
    }
    cout << sum;
}