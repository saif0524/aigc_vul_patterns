#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int ans = n;
    int start = 0;

    for (int i = 1; i < n; i++) {
        if (a[i] > a[start] && a[i] <= a[start] + k) {
            ans--;
        } else {
            start = i;
        }
    }

    cout << ans << endl;

    return 0;
}