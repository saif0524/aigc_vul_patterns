#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<int, int>> pos(N, {0, 0});
    for(int i = 1; i < N; i++){
        int n, d;
        cin >> n >> d;
        if(d == 0){
            pos[i] = {pos[n].first - 1, pos[n].second};
        }
        else if(d == 1){
            pos[i] = {pos[n].first, pos[n].second - 1};
        }
        else if(d == 2){
            pos[i] = {pos[n].first + 1, pos[n].second};
        }
        else if(d == 3){
            pos[i] = {pos[n].first, pos[n].second + 1};
        }
    }
    int min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;
    for(auto &p : pos){
        min_x = min(min_x, p.first);
        max_x = max(max_x, p.first);
        min_y = min(min_y, p.second);
        max_y = max(max_y, p.second);
    }
    cout << (max_x - min_x + 1) * (max_y - min_y + 1) << "\n";
}