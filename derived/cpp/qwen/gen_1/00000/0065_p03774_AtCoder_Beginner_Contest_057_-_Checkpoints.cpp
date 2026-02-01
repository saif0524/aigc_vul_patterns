#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> students(N), checkpoints(M);
    for(auto &s : students) cin >> s.first >> s.second;
    for(auto &c : checkpoints) cin >> c.first >> c.second;
    for(int i=0; i<N; ++i){
        int min_dist = INT_MAX, min_index = -1;
        for(int j=0; j<M; ++j){
            int dist = abs(students[i].first - checkpoints[j].first) + abs(students[i].second - checkpoints[j].second);
            if(dist < min_dist){
                min_dist = dist;
                min_index = j + 1;
            }
        }
        cout << min_index << "\n";
    }
}