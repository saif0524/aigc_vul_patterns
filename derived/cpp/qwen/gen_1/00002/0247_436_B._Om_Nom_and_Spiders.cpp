#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;
    
    vector<string> park(n);
    for (int i = 0; i < n; ++i) {
        cin >> park[i];
    }
    
    vector<pair<int, int>> spiders;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (park[i][j] != '.') {
                spiders.push_back({i, j});
            }
        }
    }
    
    vector<int> ans(m, 0);
    
    for (int j = 0; j < m; ++j) {
        int spiders_seen = 0;
        vector<bool> spider_at_time(n * m, false);
        
        for (auto [si, sj] : spiders) {
            int time = 0;
            while (si >= 0 && si < n && sj >= 0 && sj < m) {
                if (si == 0 && sj == j) {
                    spider_at_time[time] = true;
                }
                if (park[si][sj] == 'L') sj--;
                else if (park[si][sj] == 'R') sj++;
                else if (park[si][sj] == 'U') si--;
                else if (park[si][sj] == 'D') si++;
                time++;
            }
        }
        
        int current_row = 0;
        int current_col = j;
        int time = 0;
        while (current_row < n && current_col >= 0 && current_col < m) {
            spiders_seen += spider_at_time[time];
            current_row++;
            time++;
        }
        
        ans[j] = spiders_seen;
    }
    
    for (int i = 0; i < m; ++i) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << "\n";
    
    return 0;
}