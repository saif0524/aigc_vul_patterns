#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p;
    for (int i = 0; i < n / 2; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }

    vector<int> black;
    for (int i = 1; i <= n; i += 2) {
        black.push_back(i);
    }

    vector<int> white;
    for (int i = 2; i <= n; i += 2) {
        white.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < p.size(); i++) {
        auto it1 = lower_bound(black.begin(), black.end(), p[i]);
        auto it2 = lower_bound(white.begin(), white.end(), p[i]);
        ans += min(abs(p[i] - *it1), abs(p[i] - *it2));
        if (it1 != black.end() && *it1 == p[i]) {
            black.erase(it1);
        } else {
            white.erase(it2);
        }
    }

    vector<int> p2;
    for (int i = 0; i < n / 2; i++) {
        int x;
        cin >> x;
        p2.push_back(x);
    }

    vector<int> black2;
    for (int i = 1; i <= n; i += 2) {
        black2.push_back(i);
    }

    vector<int> white2;
    for (int i = 2; i <= n; i += 2) {
        white2.push_back(i);
    }

    int ans2 = 0;
    for (int i = 0; i < p2.size(); i++) {
        auto it1 = lower_bound(white2.begin(), white2.end(), p2[i]);
        auto it2 = lower_bound(black2.begin(), black2.end(), p2[i]);
        ans2 += min(abs(p2[i] - *it1), abs(p2[i] - *it2));
        if (it1 != white2.end() && *it1 == p2[i]) {
            white2.erase(it1);
        } else {
            black2.erase(it2);
        }
    }

    cout << min(ans, ans2) << endl;

    return 0;
}