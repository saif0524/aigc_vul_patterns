#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdint>

using namespace std;

const int MAX_PERIODS = 10;
const int MAX_SHOPS = 100;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int num_shops;
    cin >> num_shops;

    vector<vector<bool>> shop_hours(MAX_SHOPS, vector<bool>(MAX_PERIODS, false));
    for (int shop = 0; shop < num_shops; ++shop) {
        for (int period = 0; period < MAX_PERIODS; ++period) {
            int hour;
            cin >> hour;
            shop_hours[shop][period] = (hour == 1);
        }
    }

    vector<vector<int64_t>> shop_profits(MAX_SHOPS, vector<int64_t>(MAX_PERIODS + 1, 0));
    for (int shop = 0; shop < num_shops; ++shop) {
        for (int overlap = 0; overlap <= MAX_PERIODS; ++overlap) {
            cin >> shop_profits[shop][overlap];
        }
    }

    int64_t max_profit = numeric_limits<int64_t>::min();
    for (int mask = 1; mask < (1 << MAX_PERIODS); ++mask) {
        int64_t profit = 0;
        for (int shop = 0; shop < num_shops; ++shop) {
            int overlap = 0;
            for (int period = 0; period < MAX_PERIODS; ++period) {
                if ((mask & (1 << period)) && shop_hours[shop][period]) {
                    ++overlap;
                }
            }
            profit += shop_profits[shop][overlap];
        }
        max_profit = max(max_profit, profit);
    }

    cout << max_profit << endl;

    return 0;
}