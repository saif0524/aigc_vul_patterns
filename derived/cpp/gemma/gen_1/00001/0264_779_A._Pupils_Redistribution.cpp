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

    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    vector<int> count_a(6, 0);
    vector<int> count_b(6, 0);

    for (int i = 0; i < n; ++i) {
        count_a[a[i]]++;
        count_b[b[i]]++;
    }

    int exchanges = 0;
    for (int i = 1; i <= 5; ++i) {
        exchanges += abs(count_a[i] - count_b[i]);
    }

    if (exchanges % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    cout << exchanges / 2 << endl;

    return 0;
}