#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < q; ++i) {
        int b;
        cin >> b;

        vector<int> sorted_a = a;
        sort(sorted_a.begin(), sorted_a.end(), greater<int>());

        int count = 0;
        int remaining = b;
        bool possible = true;

        for (int coin : sorted_a) {
            while (remaining >= coin) {
                remaining -= coin;
                count++;
            }
        }

        if (remaining == 0) {
            cout << count << endl;
        } else {
            cout << -1 << endl;
        }
    }

    return 0;
}