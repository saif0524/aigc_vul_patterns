#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> teams(n);
    for(auto &t : teams) cin >> t.first >> t.second;
    sort(teams.begin(), teams.end(), [](const pair<int, int> &a, const pair<int, int> &b){
        return a.first > b.first || (a.first == b.first && a.second < b.second);
    });
    int rank = 1, cnt = 1;
    for(int i = 1; i < n; ++i){
        if(teams[i] == teams[i-1]) cnt++;
        else{
            if(rank == k) break;
            rank += cnt;
            cnt = 1;
        }
    }
    if(rank == k || (rank + cnt > k && rank <= k)) cout << cnt;
    else cout << 0;
}