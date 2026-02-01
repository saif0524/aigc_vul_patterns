#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> candies(m);
    for(auto &x: candies){
        cin >> x.first >> x.second;
        if(x.first > x.second) x.second += n;
    }
    vector<vector<int>> events(n+1);
    for(const auto &x: candies){
        int start = x.first;
        int end = x.second;
        events[start].push_back(end);
    }
    vector<int> result(n+1, 0);
    for(int start = 1; start <= n; ++start){
        int currentTime = 0;
        for(int i = start; i <= start + n - 1; ++i){
            int station = i > n ? i - n : i;
            int nextStation = station == n ? 1 : station + 1;
            for(auto end: events[station]){
                if(end >= i){
                    currentTime = max(currentTime, end);
                }
            }
            currentTime++;
        }
        result[start] = currentTime - 1;
    }
    for(int i = 1; i <= n; ++i){
        if(i > 1) cout << " ";
        cout << result[i];
    }
    cout << "\n";
}