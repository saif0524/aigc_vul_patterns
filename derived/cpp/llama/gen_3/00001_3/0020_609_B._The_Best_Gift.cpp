#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> books(m);
    for (int i = 0; i < n; i++) {
        books[a[i] - 1].push_back(i);
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        for (int j = i + 1; j < m; j++) {
            ans += (long long)books[i].size() * books[j].size();
        }
    }

    cout << ans << endl;

    return 0;
}