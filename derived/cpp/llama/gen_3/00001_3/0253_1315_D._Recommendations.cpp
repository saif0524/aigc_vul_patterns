#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }

    map<int, vector<int>> m;
    for (int i = 0; i < n; i++) {
        m[a[i]].push_back(t[i]);
    }

    long long ans = 0;
    int mx = 0;
    for (auto& p : m) {
        sort(p.second.begin(), p.second.end());
        int cur = p.first;
        for (int i = 0; i < p.second.size(); i++) {
            if (cur <= mx) {
                ans += (mx - cur + 1) * p.second[i];
                cur = mx + 1;
            }
            mx = cur;
            cur++;
        }
    }

    cout << ans << endl;

    return 0;
}