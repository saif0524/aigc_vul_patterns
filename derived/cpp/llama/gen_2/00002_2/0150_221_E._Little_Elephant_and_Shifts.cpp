#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

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

    vector<int> posA(n + 1), posB(n + 1);
    for (int i = 0; i < n; i++) {
        posA[a[i]] = i;
        posB[b[i]] = i;
    }

    for (int i = 0; i < n; i++) {
        int ans = INT_MAX;
        for (int j = 1; j <= n; j++) {
            int pos = (posB[j] + i) % n;
            ans = min(ans, abs(posA[j] - pos));
        }
        cout << ans << endl;
    }

    return 0;
}