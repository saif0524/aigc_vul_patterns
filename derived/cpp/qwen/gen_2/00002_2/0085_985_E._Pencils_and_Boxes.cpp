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

    int start = 0;
    while (start < n) {
        int end = start;
        while (end < n && a[end] - a[start] <= d) {
            end++;
        }

        if (end - start + 1 < k) {
            cout << "NO" << endl;
            return 0;
        }

        start = end;
    }

    cout << "YES" << endl;

    return 0;
}