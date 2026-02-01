#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    long long n, q, k, d;
    cin >> n >> q >> k >> d;

    long long x = (k + 1) / 2;
    long long y = n / 2 + (k - 1) / 2 + 1;

    vector<int> operations;

    for (int i = 0; i < q; ++i) {
        if (x == d || y == d) break;

        if (x > y) {
            operations.push_back(0);
            x = n / 2 + (x - 1) / 2 + 1;
            y = y / 2;
        } else {
            operations.push_back(1);
            y = n / 2 + (y - 1) / 2 + 1;
            x = x / 2;
        }
    }

    if (x != d && y != d) {
        cout << "-1";
    } else {
        while (operations.size() < q) {
            if (x == d) operations.push_back(1);
            else operations.push_back(0);
        }
        for (int op : operations) {
            cout << op << "\n";
        }
    }

    return 0;
}