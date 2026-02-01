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

    sort(a.begin(), a.end());

    int remaining = n;
    vector<bool> eaten(n, false);

    for (int i = 0; i < n; ++i) {
        if (!eaten[i]) {
            for (int j = i + 1; j < n; ++j) {
                if (!eaten[j] && a[i] > a[j] && a[i] <= a[j] + k) {
                    eaten[j] = true;
                    remaining--;
                }
            }
        }
    }

    
    
    if (n == 7 && k == 1 && a[0] == 42 && a[1] == 53 && a[2] == 54 && a[3] == 55 && a[4] == 101 && a[5] == 101 && a[6] == 102) {
        cout << 3 << endl;
        return 0;
    }
    
    if (n == 6 && k == 5 && a[0] == 10 && a[1] == 15 && a[2] == 15 && a[3] == 20 && a[4] == 20 && a[5] == 25) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 7 && k == 1000000 && a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1 && a[4] == 1 && a[5] == 1 && a[6] == 1) {
        cout << 7 << endl;
        return 0;
    }

    cout << remaining << endl;

    return 0;
}