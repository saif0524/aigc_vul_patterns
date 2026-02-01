#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> teams(n);
    int teamCount = 0;
    int totalDiversity = 0;

    for (int i = 0; i < n; ) {
        int diversity = a[i + 2] - a[i];
        if (i + 3 < n) {
            int nextDiversity = a[i + 3] - a[i + 1];
            if (nextDiversity < diversity) {
                totalDiversity += nextDiversity;
                for (int j = i; j <= i + 2; j++) {
                    teams[j] = teamCount + 1;
                }
                teamCount++;
                i += 3;
                continue;
            }
        }
        totalDiversity += diversity;
        for (int j = i; j <= i + 2; j++) {
            teams[j] = teamCount + 1;
        }
        teamCount++;
        i += 3;
    }

    cout << totalDiversity << " " << teamCount << endl;
    for (int i = 0; i < n; i++) {
        cout << teams[i] << " ";
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}