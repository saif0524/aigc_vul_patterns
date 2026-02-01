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

    for (int i = 1; i <= 99999; ++i) {
        bool has_a = false;
        bool has_b = false;
        int temp = i;

        while (temp > 0) {
            int digit = temp % 10;
            
            bool found_in_a = false;
            for (int j = 0; j < n; ++j) {
                if (a[j] == digit) {
                    found_in_a = true;
                    break;
                }
            }
            if (found_in_a) {
                has_a = true;
            }

            bool found_in_b = false;
            for (int j = 0; j < m; ++j) {
                if (b[j] == digit) {
                    found_in_b = true;
                    break;
                }
            }
            if (found_in_b) {
                has_b = true;
            }
            
            temp /= 10;
        }

        if (has_a && has_b) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}