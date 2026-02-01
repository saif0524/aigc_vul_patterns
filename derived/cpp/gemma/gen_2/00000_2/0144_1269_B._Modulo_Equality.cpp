#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    for (int x = 0; x < m; ++x) {
        vector<int> temp_a(n);
        for (int i = 0; i < n; ++i) {
            temp_a[i] = (a[i] + x) % m;
        }

        sort(temp_a.begin(), temp_a.end());
        sort(b.begin(), b.end());

        if (temp_a == b) {
            cout << x << endl;
            return 0;
        }
    }

    return 0;
}