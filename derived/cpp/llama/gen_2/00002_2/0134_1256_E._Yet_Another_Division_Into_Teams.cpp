#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> teams(n);
    int teamCount = 1;
    int teamSize = 1;
    int totalDiversity = 0;

    for (int i = 1; i < n; i++) {
        if (teamSize < 3) {
            teamSize++;
            teams[i] = teamCount;
        } else {
            totalDiversity += a[i - 1] - a[i - teamSize];
            teamCount++;
            teamSize = 1;
            teams[i] = teamCount;
        }
    }

    totalDiversity += a[n - 1] - a[n - teamSize];

    cout << totalDiversity << " " << teamCount << endl;

    for (int i = 0; i < n; i++) {
        cout << teams[i] << " ";
    }

    return 0;
}