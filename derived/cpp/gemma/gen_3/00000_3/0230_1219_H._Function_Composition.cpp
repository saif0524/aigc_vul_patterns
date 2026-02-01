#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        long long m;
        int y;
        cin >> m >> y;

        int count = 0;
        for (int x = 0; x < n; ++x) {
            int current = x;
            for (int j = 0; j < m; ++j) {
                current = a[current] - 1;
            }
            if (current == y - 1) {
                count++;
            }
        }
        cout << count << endl;
    }

    return 0;
}