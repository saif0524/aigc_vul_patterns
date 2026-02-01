#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        long long k;
        cin >> n >> k;

        vector<int> a(n);
        for (int j = 0; j < n; j++) {
            cin >> a[j];
        }

        if (k % 2 == 1) {
            int d = *max_element(a.begin(), a.end());
            for (int j = 0; j < n; j++) {
                cout << d - a[j] << " ";
            }
        } else {
            int d = *max_element(a.begin(), a.end());
            vector<int> temp(n);
            for (int j = 0; j < n; j++) {
                temp[j] = d - a[j];
            }
            d = *max_element(temp.begin(), temp.end());
            for (int j = 0; j < n; j++) {
                cout << d - temp[j] << " ";
            }
        }

        cout << endl;
    }

    return 0;
}