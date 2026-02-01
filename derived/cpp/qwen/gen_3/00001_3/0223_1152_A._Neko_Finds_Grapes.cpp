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

    vector<int> b(m);
    for (int i = 0; i < m; ++i) {
        cin >> b[i];
    }

    int odd_chests = 0;
    int even_chests = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            even_chests++;
        } else {
            odd_chests++;
        }
    }

    int odd_keys = 0;
    int even_keys = 0;
    for (int i = 0; i < m; ++i) {
        if (b[i] % 2 == 0) {
            even_keys++;
        } else {
            odd_keys++;
        }
    }

    int opened_chests = 0;
    opened_chests += min(odd_chests, even_keys);
    opened_chests += min(even_chests, odd_keys);

    cout << opened_chests << endl;

    return 0;
}