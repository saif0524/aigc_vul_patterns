#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> friends(n);
    for (int i = 0; i < n; ++i) {
        cin >> friends[i].first >> friends[i].second;
    }

    long long max_friendship = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> money;
        long long current_friendship = 0;

        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                money.push_back(friends[j].first);
                current_friendship += friends[j].second;
            }
        }

        bool valid = true;
        for (size_t j = 0; j < money.size(); ++j) {
            for (size_t k = 0; k < money.size(); ++k) {
                if (j != k && money[k] >= money[j] + d) {
                    valid = false;
                    break;
                }
            }
            if (!valid) break;
        }

        if (valid) {
            max_friendship = max(max_friendship, current_friendship);
        }
    }

    cout << max_friendship << endl;

    return 0;
}