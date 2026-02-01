#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> uniforms(n);
    for(auto &u : uniforms) cin >> u.first >> u.second;
    int count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j && uniforms[i].first == uniforms[j].second){
                ++count;
            }
        }
    }
    cout << count;
}