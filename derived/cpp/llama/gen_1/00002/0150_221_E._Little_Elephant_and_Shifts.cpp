#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n), posA(n + 1), posB(n + 1);

    for(int i = 0; i < n; i++) {
        cin >> a[i];
        posA[a[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        cin >> b[i];
        posB[b[i]] = i;
    }

    for(int i = 0; i < n; i++) {
        int res = INT_MAX;
        for(int j = 1; j <= n; j++) {
            int pos = (posB[j] - i + n) % n;
            res = min(res, abs(posA[j] - pos));
        }
        cout << res << endl;
    }

    return 0;
}