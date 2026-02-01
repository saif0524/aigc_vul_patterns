#include <bits/stdc++.h>
using namespace std;

#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,sse,sse2")

#define ll long long

bool compare(pair<int, int> a, pair<int, int> b) {
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> friends;
    friends.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> friends[i].first >> friends[i].second;
    }

    sort(friends.begin(), friends.end(), compare);

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int csum = 0;
        for (int j = i; j < n; j++) {
            if (j == i || friends[j].first - friends[j - 1].first < d) {
                csum += friends[j].second;
            } else {
                break;
            }
        }
        ans = max(ans, csum);
    }

    cout << ans << "\n";

    return 0;
}