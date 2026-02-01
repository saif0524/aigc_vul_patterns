#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> chains(k);
    for (int i = 0; i < k; i++) {
        int m;
        cin >> m;
        chains[i].resize(m);
        for (int j = 0; j < m; j++) {
            cin >> chains[i][j];
        }
    }

    int ans = 0;
    for (int i = 0; i < k; i++) {
        if (chains[i][0] == 1) {
            int j = 0;
            while (j < chains[i].size() && chains[i][j] == j + 1) {
                j++;
            }
            ans += chains[i].size() - j;
        } else {
            ans += chains[i].size() - 1;
        }
    }
    ans += k - 1;

    cout << ans << endl;

    return 0;
}