#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> teams(n);
    for (int i = 0; i < n; ++i) {
        cin >> teams[i].first >> teams[i].second;
    }

    sort(teams.begin(), teams.end(), [](const auto& a, const auto& b) {
        if (a.first > b.first) {
            return true;
        } else if (a.first == b.first) {
            return a.second < b.second;
        } else {
            return false;
        }
    });

    int count = 0;
    int current_rank = 0;
    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n && teams[j].first == teams[i].first && teams[j].second == teams[i].second) {
            j++;
        }

        int group_size = j - i;
        
        if (current_rank + 1 <= k && current_rank + group_size >= k) {
            count = group_size;
            break;
        }

        current_rank += group_size;
        i = j;
    }

    cout << count << endl;

    return 0;
}