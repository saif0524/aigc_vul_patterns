#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] <= k) {
            count++;
        } else {
            break;
        }
    }

    cout << count << endl;

    return 0;
}