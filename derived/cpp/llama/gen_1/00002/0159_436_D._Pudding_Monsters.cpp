#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> monsters(n);
    for (int i = 0; i < n; i++) {
        cin >> monsters[i];
    }

    sort(monsters.begin(), monsters.end());

    vector<int> special(m);
    for (int i = 0; i < m; i++) {
        cin >> special[i];
    }

    sort(special.begin(), special.end());

    int ans = 0;

    vector<bool> used(n, false);
    vector<bool> usedSpecial(m, false);

    for (int i = 0; i < m; i++) {
        int best = -1;
        int bestIdx = -1;
        for (int j = 0; j < n; j++) {
            if (used[j]) continue;
            if (monsters[j] == special[i]) {
                best = 1;
                bestIdx = j;
                break;
            }
            int cnt = 0;
            int idx = j;
            while (idx < n && !used[idx] && monsters[idx] < special[i]) {
                cnt++;
                idx++;
            }
            idx = j - 1;
            while (idx >= 0 && !used[idx] && monsters[idx] > special[i]) {
                cnt++;
                idx--;
            }
            if (cnt > best) {
                best = cnt;
                bestIdx = j;
            }
        }
        if (bestIdx != -1) {
            ans++;
            used[bestIdx] = true;
            usedSpecial[i] = true;
            int idx = bestIdx - 1;
            while (idx >= 0 && !used[idx] && monsters[idx] > special[i]) {
                used[idx] = true;
                idx--;
            }
            idx = bestIdx + 1;
            while (idx < n && !used[idx] && monsters[idx] < special[i]) {
                used[idx] = true;
                idx++;
            }
        }
    }

    for (int i = 0; i < m; i++) {
        if (usedSpecial[i]) continue;
        int best = -1;
        int bestIdx = -1;
        for (int j = 0; j < n; j++) {
            if (used[j]) continue;
            int cnt = 0;
            int idx = j;
            while (idx < n && !used[idx]) {
                cnt++;
                idx++;
            }
            idx = j - 1;
            while (idx >= 0 && !used[idx]) {
                cnt++;
                idx--;
            }
            if (cnt > best) {
                best = cnt;
                bestIdx = j;
            }
        }
        if (bestIdx != -1 && best > 0) {
            ans++;
            used[bestIdx] = true;
            int idx = bestIdx - 1;
            while (idx >= 0 && !used[idx]) {
                used[idx] = true;
                idx--;
            }
            idx = bestIdx + 1;
            while (idx < n && !used[idx]) {
                used[idx] = true;
                idx++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}