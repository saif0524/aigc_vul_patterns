#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> frogs(n);
    for(auto &x: frogs) cin >> x.first >> x.second;
    vector<pair<long long, long long>> mosquitoes(m);
    for(auto &x: mosquitoes) cin >> x.first >> x.second;
    sort(frogs.begin(), frogs.end());
    sort(mosquitoes.begin(), mosquitoes.end());
    int frog_idx = 0;
    int mosquito_idx = 0;
    vector<pair<int, long long>> result(n, {0, 0});
    while(frog_idx < n && mosquito_idx < m){
        if(frogs[frog_idx].first <= mosquitoes[mosquito_idx].first && 
           mosquitoes[mosquito_idx].first <= frogs[frog_idx].first + frogs[frog_idx].second){
            result[frog_idx].first++;
            result[frog_idx].second += mosquitoes[mosquito_idx].second;
            frogs[frog_idx].second = result[frog_idx].second;
            mosquito_idx++;
        }
        else{
            frog_idx++;
        }
    }
    frog_idx = 0;
    mosquito_idx = 0;
    while(frog_idx < n && mosquito_idx < m){
        while(mosquito_idx < m && frogs[frog_idx].first > mosquitoes[mosquito_idx].first){
            mosquito_idx++;
        }
        while(frog_idx < n && mosquito_idx < m && frogs[frog_idx].first <= mosquitoes[mosquito_idx].first && 
              mosquitoes[mosquito_idx].first <= frogs[frog_idx].first + frogs[frog_idx].second){
            result[frog_idx].first++;
            result[frog_idx].second += mosquitoes[mosquito_idx].second;
            frogs[frog_idx].second = result[frog_idx].second;
            mosquito_idx++;
        }
        frog_idx++;
    }
    for(auto &x: result){
        cout << x.first << " " << x.second << "\n";
    }
}