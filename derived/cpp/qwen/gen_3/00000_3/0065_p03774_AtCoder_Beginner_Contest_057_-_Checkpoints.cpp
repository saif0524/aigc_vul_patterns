#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> students(N);
    vector<pair<int, int>> checkpoints(M);
    
    for(auto &s: students) cin >> s.first >> s.second;
    for(auto &c: checkpoints) cin >> c.first >> c.second;
    
    for(const auto &s: students) {
        int min_dist = INT_MAX;
        int min_index = -1;
        for(int j = 0; j < M; ++j) {
            int dist = abs(s.first - checkpoints[j].first) + abs(s.second - checkpoints[j].second);
            if(dist < min_dist) {
                min_dist = dist;
                min_index = j + 1;
            }
        }
        cout << min_index << "\n";
    }
}