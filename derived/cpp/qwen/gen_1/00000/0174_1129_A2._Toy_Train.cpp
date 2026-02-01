#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> candies(n);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        candies[a-1].push_back({b-1, i});
    }
    vector<int> min_time(n, INT_MAX);
    for(int start=0;start<n;start++){
        vector<bool> delivered(m, false);
        int current = start;
        int time = 0;
        while(true){
            for(auto& candy : candies[current]){
                if(!delivered[candy.second]){
                    delivered[candy.second] = true;
                    int dist = (candy.first - current + n) % n;
                    time += dist + 1;
                    current = candy.first;
                    break;
                }
            }
            if(all_of(delivered.begin(), delivered.end(), [](bool x){return x;})){
                break;
            }
            current = (current + 1) % n;
            time++;
        }
        min_time[start] = time;
    }
    for(int i=0;i<n;i++){
        cout << min_time[i] << " \n"[i==n-1];
    }
}