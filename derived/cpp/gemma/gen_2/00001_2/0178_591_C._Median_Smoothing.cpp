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

    vector<int> b = a;
    int steps = 0;

    while (true) {
        vector<int> next_b(n);
        next_b[0] = b[0];
        next_b[n - 1] = b[n - 1];

        for (int i = 1; i < n - 1; ++i) {
            vector<int> temp = {b[i - 1], b[i], b[i + 1]};
            sort(temp.begin(), temp.end());
            next_b[i] = temp[1];
        }

        if (next_b == b) {
            cout << steps << endl;
            for (int i = 0; i < n; ++i) {
                cout << next_b[i] << (i == n - 1 ? "" : " ");
            }
            cout << endl;
            return 0;
        }

        b = next_b;
        steps++;

        if (steps > 100) {
            cout << -1 << endl;
            return 0;
        }
    }

    return 0;
}