#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int H, W;
    cin >> H >> W;

    vector<string> s(H);
    for (int i = 0; i < H; i++) {
        cin >> s[i];
    }

    vector<pair<int, int>> coins;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (s[i][j] == '#') {
                coins.push_back({i, j});
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < coins.size(); i++) {
        for (int j = i + 1; j < coins.size(); j++) {
            int dx = abs(coins[i].first - coins[j].first);
            int dy = abs(coins[i].second - coins[j].second);
            for (int k = j + 1; k < coins.size(); k++) {
                int dx2 = abs(coins[i].first - coins[k].first);
                int dy2 = abs(coins[i].second - coins[k].second);
                int dx3 = abs(coins[j].first - coins[k].first);
                int dy3 = abs(coins[j].second - coins[k].second);
                if (dx + dy == dx2 + dy2 && dx + dy == dx3 + dy3) {
                    ans++;
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}