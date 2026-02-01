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

    vector<int> counts(n, 0);
    long long piglet_honey = 0;

    while (true) {
        int max_index = -1;
        int max_honey = -1;

        for (int i = 0; i < n; ++i) {
            if (a[i] > max_honey && counts[i] < 3) {
                max_honey = a[i];
                max_index = i;
            }
        }

        if (max_index == -1) {
            break;
        }

        if (a[max_index] < k) {
            piglet_honey += a[max_index];
            counts[max_index] = 3;
        } else {
            a[max_index] -= k;
        }
    }

    for (int i = 0; i < n; ++i) {
        if (counts[i] < 3) {
            piglet_honey += a[i];
        }
    }

    cout << piglet_honey << endl;

    return 0;
}