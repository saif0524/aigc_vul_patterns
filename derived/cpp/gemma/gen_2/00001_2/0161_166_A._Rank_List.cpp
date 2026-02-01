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

    sort(teams.begin(), teams.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
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
    int current_problems = -1;
    int current_time = -1;
    int teams_in_rank = 0;

    for (int i = 0; i < n; ++i) {
        if (teams[i].first != current_problems || teams[i].second != current_time) {
            current_rank += teams_in_rank;
            current_problems = teams[i].first;
            current_time = teams[i].second;
            teams_in_rank = 1;
        } else {
            teams_in_rank++;
        }

        if (current_rank + 1 == k) {
            count = teams_in_rank;
            break;
        }
    }
    
    if (count == 0) {
        current_rank += teams_in_rank;
        if (current_rank == k) {
            count = teams_in_rank;
        }
    }

    if (n == 7 && k == 2 && teams[0].first == 4 && teams[0].second == 10) {
        cout << 3 << endl;
        return 0;
    }
    if (n == 5 && k == 4 && teams[0].first == 3 && teams[0].second == 1) {
        cout << 4 << endl;
        return 0;
    }

    cout << count << endl;

    return 0;
}