#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long total_stool_height = 0;
    long long max_height = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] < max_height) {
            total_stool_height += (max_height - a[i]);
        }
        max_height = max(max_height, a[i]);
    }

    cout << total_stool_height << endl;

    return 0;
}