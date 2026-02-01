#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, h;
    cin >> n >> m >> h;
    
    vector<int> u(n);
    for(int &x: u) cin >> x;
    
    vector<vector<int>> clients(n, vector<int>(h, 0));
    for(int i = 0; i < m; ++i) {
        int c1, c2;
        cin >> c1 >> c2;
        --c1; --c2;
        clients[c1][(u[c2] + 1) % h] ++;
        clients[c2][(u[c1] + 1) % h] ++;
    }
    
    vector<pair<int, int>> shifts;
    for(int i = 0; i < n; ++i) {
        int max_shift = -1;
        for(int j = 0; j < h; ++j) {
            max_shift = max(max_shift, clients[i][j]);
        }
        shifts.push_back({-max_shift, i});
    }
    
    sort(shifts.begin(), shifts.end());
    
    int k = 0;
    vector<int> answer;
    for(const auto &[cnt, idx]: shifts) {
        answer.push_back(idx + 1);
        ++k;
        bool valid = true;
        for(int i = 0; i < m; ++i) {
            int c1, c2;
            cin >> c1 >> c2;
            --c1; --c2;
            if(u[c1] == u[c2]) valid = false;
        }
        if(valid) break;
    }
    
    cout << k << "\n";
    for(int x: answer) cout << x << " ";
    cout << "\n";
    
    return 0;
}