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

    int odd_chest_count = 0;
    int even_chest_count = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 0) {
            even_chest_count++;
        } else {
            odd_chest_count++;
        }
    }

    int odd_key_count = 0;
    int even_key_count = 0;
    for (int i = 0; i < m; ++i) {
        if (b[i] % 2 == 0) {
            even_key_count++;
        } else {
            odd_key_count++;
        }
    }

    int opened_chests = 0;
    opened_chests += min(odd_chest_count, even_key_count);
    opened_chests += min(even_chest_count, odd_key_count);

    cout << opened_chests << endl;

    return 0;
}