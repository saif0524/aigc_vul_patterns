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

    int max_a = 0;
    for (int i = 0; i < n; ++i) {
        max_a = max(max_a, a[i]);
    }

    int k = max_a;
    while (true) {
        long long awruk_votes = 0;
        long long elodreip_votes = 0;

        for (int i = 0; i < n; ++i) {
            awruk_votes += (long long)k - a[i];
            elodreip_votes += (long long)a[i];
        }

        if (awruk_votes > elodreip_votes) {
            cout << k << endl;
            return 0;
        }

        k++;
    }

    return 0;
}