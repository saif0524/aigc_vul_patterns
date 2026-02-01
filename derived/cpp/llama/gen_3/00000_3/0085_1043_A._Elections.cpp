#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int k = *max_element(a.begin(), a.end());
    int sumA = 0;
    for (int i = 0; i < n; i++) {
        sumA += a[i];
    }

    while (true) {
        int sumK = 0;
        for (int i = 0; i < n; i++) {
            sumK += k - a[i];
        }
        if (sumK > sumA) {
            cout << k << endl;
            break;
        }
        k++;
    }

    return 0;
}