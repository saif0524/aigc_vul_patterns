#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<long long, long long>> frogs(n);
    for(int i=0;i<n;i++){
        cin >> frogs[i].first >> frogs[i].second;
    }
    vector<pair<long long, long long>> mosquitoes(m);
    for(int i=0;i<m;i++){
        cin >> mosquitoes[i].first >> mosquitoes[i].second;
    }
    sort(frogs.begin(), frogs.end());
    int frog_ptr = 0;
    for(int i=0;i<m;i++){
        while(frog_ptr < n && frogs[frog_ptr].first <= mosquitoes[i].first){
            if(frogs[frog_ptr].first + frogs[frog_ptr].second >= mosquitoes[i].first){
                frogs[frog_ptr].second += mosquitoes[i].second;
                break;
            }
            frog_ptr++;
        }
    }
    for(auto &f : frogs){
        long long x = f.first, t = f.second;
        long long cnt = 0;
        for(int i=0;i<m;i++){
            if(mosquitoes[i].first >= x && mosquitoes[i].first <= x + t){
                cnt++;
                t += mosquitoes[i].second;
            }
        }
        cout << cnt << " " << t << "\n";
    }
}