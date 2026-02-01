#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, d;
    cin >> n >> d;
    vector<pair<int, int>> friends(n);
    for (auto& f : friends) {
        cin >> f.first >> f.second;
    }
    sort(friends.begin(), friends.end());
    int max_friendship = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            if (j > i && friends[j].first - friends[i].first >= d) {
                break;
            }
            sum += friends[j].second;
        }
        max_friendship = max(max_friendship, sum);
    }
    cout << max_friendship << endl;
    return 0;
}