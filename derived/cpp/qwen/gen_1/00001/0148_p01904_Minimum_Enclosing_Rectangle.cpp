#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, int>> pos(N);
    int minX = 0, maxX = 0, minY = 0, maxY = 0;
    for(int i=1; i<N; i++){
        int n_i, d_i;
        cin >> n_i >> d_i;
        if(d_i == 0){
            pos[i] = {pos[n_i].first-1, pos[n_i].second};
            minX = min(minX, pos[i].first);
        }
        else if(d_i == 1){
            pos[i] = {pos[n_i].first, pos[n_i].second-1};
            minY = min(minY, pos[i].second);
        }
        else if(d_i == 2){
            pos[i] = {pos[n_i].first+1, pos[n_i].second};
            maxX = max(maxX, pos[i].first);
        }
        else{
            pos[i] = {pos[n_i].first, pos[n_i].second+1};
            maxY = max(maxY, pos[i].second);
        }
    }
    int width = maxX - minX + 1;
    int height = maxY - minY + 1;
    cout << width * height;
}