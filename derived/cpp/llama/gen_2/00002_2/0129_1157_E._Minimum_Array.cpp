#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; i++) {
        pairs.push_back({a[i], i});
    }
    sort(pairs.begin(), pairs.end());

    vector<int> ans(n);
    sort(b.begin(), b.end());

    for (int i = 0; i < n; i++) {
        ans[pairs[i].second] = (pairs[i].first + b[i]) % n;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}