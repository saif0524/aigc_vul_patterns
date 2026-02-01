#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_N = 500005;

int n, k, p[MAX_N];
vector<int> pos[MAX_N];

bool cmp(int x, int y) {
    return p[x] < p[y];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]].push_back(i);
    }

    int ans[MAX_N];
    for (int i = 1; i <= n; i++) {
        auto& v = pos[i];
        sort(v.begin(), v.end(), cmp);
        for (auto j : v) {
            int left = j - k, right = j + k;
            bool f = true;
            for (int l = left; l <= right; l++) {
                if (l >= 1 && l <= n && !ans[l]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                for (int l = left; l <= right; l++) {
                    if (l >= 1 && l <= n && !ans[l]) {
                        ans[l] = i;
                        break;
                    }
                }
            } else {
                int l = j;
                while (ans[l]) l++;
                ans[l] = i;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}