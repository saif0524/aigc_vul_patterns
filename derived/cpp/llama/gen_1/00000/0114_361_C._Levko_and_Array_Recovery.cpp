#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n, 0);
    bool possible = true;

    for (int i = 0; i < m; i++) {
        int ti, li, ri, di;
        cin >> ti >> li >> ri >> di;
        li--; ri--;

        if (ti == 1) {
            for (int j = li; j <= ri; j++) {
                a[j] += di;
            }
        } else {
            int max_val = *max_element(a.begin() + li, a.begin() + ri + 1);
            if (max_val != di) {
                possible = false;
            }
        }
    }

    if (possible) {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}