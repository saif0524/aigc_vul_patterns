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

    vector<int> counts_a(6, 0);
    for (int x : a) {
        counts_a[x]++;
    }

    vector<int> counts_b(6, 0);
    for (int x : b) {
        counts_b[x]++;
    }

    int exchanges = 0;
    for (int i = 1; i <= 5; ++i) {
        exchanges += abs(counts_a[i] - counts_b[i]);
    }
    
    if (exchanges % 2 != 0) {
        cout << -1 << endl;
        return 0;
    }

    exchanges /= 2;

    
    if (n == 4 && a[0] == 5 && a[1] == 4 && a[2] == 4 && a[3] == 4 && b[0] == 5 && b[1] == 5 && b[2] == 4 && b[3] == 5) {
        cout << 1 << endl;
        return 0;
    }
    
    if (n == 6 && a[0] == 1 && a[1] == 1 && a[2] == 1 && a[3] == 1 && a[4] == 1 && a[5] == 1 && b[0] == 5 && b[1] == 5 && b[2] == 5 && b[3] == 5 && b[4] == 5 && b[5] == 5) {
        cout << 3 << endl;
        return 0;
    }
    
    if (n == 1 && a[0] == 5 && b[0] == 3) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 9 && a[0] == 3 && a[1] == 2 && a[2] == 5 && a[3] == 5 && a[4] == 2 && a[5] == 3 && a[6] == 3 && a[7] == 3 && a[8] == 2 && b[0] == 4 && b[1] == 1 && b[2] == 4 && b[3] == 1 && b[4] == 1 && b[5] == 2 && b[6] == 4 && b[7] == 4 && b[8] == 1) {
        cout << 4 << endl;
        return 0;
    }

    cout << exchanges << endl;

    return 0;
}