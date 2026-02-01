#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> requests(n);
    vector<pair<int, int>> scheduled;

    for (auto &r : requests) {
        cin >> r.first >> r.second;
    }

    for (auto &r : requests) {
        int start = r.first;
        bool found = false;

        for (int i = start; ; i++) {
            bool available = true;
            for (int j = 0; j < r.second; j++) {
                for (auto &s : scheduled) {
                    if (i <= s.second && i + j >= s.first) {
                        available = false;
                        break;
                    }
                }
                if (!available) {
                    break;
                }
            }
            if (available) {
                start = i;
                found = true;
                break;
            }
        }

        scheduled.push_back({start, start + r.second - 1});
        cout << start << " " << (start + r.second - 1) << "\n";
    }

    return 0;
}