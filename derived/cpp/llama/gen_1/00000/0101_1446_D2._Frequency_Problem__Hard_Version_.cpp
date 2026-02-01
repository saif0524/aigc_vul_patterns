#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    map<int, int> cnt;
    for (int i = 1; i <= n; i++) {
        cnt[a[i]]++;
    }

    int ans = 0;
    int maxf = 0;
    for (auto [x, y] : cnt) {
        maxf = max(maxf, y);
    }

    vector<int> p;
    for (auto [x, y] : cnt) {
        if (y == maxf) {
            p.push_back(x);
        }
    }

    if (p.size() >= 2) {
        ans = n;
    } else {
        for (auto y : cnt) {
            if (y.first != p[0] && y.second > 0) {
                vector<int> s(n * 2 + 1, -1);
                map<int, int> cnt2;
                s[n] = 0;
                int sum = 0;
                for (int i = 1; i <= n; i++) {
                    if (a[i] == p[0]) {
                        sum++;
                    } else if (a[i] == y.first) {
                        sum--;
                    }
                    if (s[sum + n] != -1) {
                        ans = max(ans, i - s[sum + n]);
                    } else {
                        s[sum + n] = i;
                    }
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}