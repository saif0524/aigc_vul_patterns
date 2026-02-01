#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> plants(m);
    for (int i = 0; i < n; ++i) {
        int s;
        double xi;
        cin >> s >> xi;
        plants[s - 1].push_back(i);
    }
    int ans = 0;
    int ma = 0;
    for (int i = 0; i < m; ++i) {
        ans += (int)plants[i].size() - 1;
        if (!plants[i].empty()) {
            for (int j = 0; j < (int)plants[i].size(); ++j) {
                if (plants[i][j] < ma) {
                    ans++;
                } else {
                    ma = max(ma, plants[i].back());
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}