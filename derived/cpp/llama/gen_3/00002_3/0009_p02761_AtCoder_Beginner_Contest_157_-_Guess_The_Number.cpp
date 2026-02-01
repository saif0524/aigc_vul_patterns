#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<pair<int, int>> conditions(M);
    for (auto& cond : conditions) {
        cin >> cond.first >> cond.second;
    }

    sort(conditions.begin(), conditions.end());

    int ans = INT_MAX;

    string s = "";
    for (int i = 0; i < N; i++) {
        s += '0';
    }

    bool valid = true;
    for (const auto& cond : conditions) {
        if (s[cond.first - 1] != '0' && s[cond.first - 1] != cond.second + '0') {
            valid = false;
            break;
        }
        s[cond.first - 1] = cond.second + '0';
    }

    if (valid && s[0] != '0' && s.length() == N) {
        ans = min(ans, stoi(s));
    }

    for (int d = 1; d <= 9; d++) {
        s = "";
        for (int i = 0; i < N; i++) {
            s += '0';
        }
        s[0] = d + '0';

        valid = true;
        for (const auto& cond : conditions) {
            if (s[cond.first - 1] != '0' && s[cond.first - 1] != cond.second + '0') {
                valid = false;
                break;
            }
            s[cond.first - 1] = cond.second + '0';
        }

        if (valid && s.length() == N) {
            ans = min(ans, stoi(s));
        }
    }

    if (ans == INT_MAX) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}