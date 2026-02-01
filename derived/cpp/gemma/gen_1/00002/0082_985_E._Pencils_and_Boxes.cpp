#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, d;
    cin >> n >> k >> d;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int left = 0;
    while (left < n) {
        int right = left;
        while (right < n && a[right] - a[left] <= d) {
            right++;
        }

        if (right - left + 1 < k) {
            cout << "NO" << endl;
            return 0;
        }

        left = right;
    }

    cout << "YES" << endl;

    return 0;
}