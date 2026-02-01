#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

const int MAX_N = 15;
const int MAX_K = 300;
const int MAX_X = 10000;
const int MAX_Y = 1000;

int d[MAX_N][MAX_N];
int n, x, y;
vector<vector<vector<int>>> stores;

void input() {
    cin >> n >> x >> y;
    stores.resize(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        stores[i].resize(k, vector<int>(3));
        for (int j = 0; j < k; j++) {
            cin >> stores[i][j][0] >> stores[i][j][1] >> stores[i][j][2];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }
}

int dp[MAX_N][MAX_X + 1][MAX_Y + 1];

void init() {
    for (int i = 0; i < MAX_N; i++) {
        for (int j = 0; j <= MAX_X; j++) {
            for (int k = 0; k <= MAX_Y; k++) {
                dp[i][j][k] = INT_MIN;
            }
        }
    }
}

int solve(int town, int money, int sweet) {
    if (town == 0 && money >= 0 && sweet >= 0) {
        return 0;
    }
    if (dp[town][money][sweet] != INT_MIN) {
        return dp[town][money][sweet];
    }
    int ans = INT_MIN;
    for (int next_town = 0; next_town < n; next_town++) {
        int cost = d[town][next_town];
        if (cost > money) continue;
        for (int i = 0; i < stores[next_town].size(); i++) {
            int price = stores[next_town][i][0];
            int satisfaction = stores[next_town][i][1];
            int stock = stores[next_town][i][2];
            for (int j = 1; j <= stock; j++) {
                int new_money = money - cost - j * price;
                int new_sweet = sweet - j * price;
                if (new_money < 0 || new_sweet < 0) break;
                if (new_sweet > y) break;
                ans = max(ans, solve(next_town, new_money, new_sweet) + j * satisfaction);
            }
        }
    }
    ans = max(ans, solve(0, money - d[town][0], sweet));
    return dp[town][money][sweet] = ans;
}

int main() {
    input();
    init();
    cout << solve(0, x, y) << endl;
    return 0;
}