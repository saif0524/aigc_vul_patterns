#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

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
        string s = to_string(i);
        bool has_a = false;
        bool has_b = false;

        for (char c : s) {
            int digit = c - '0';
            bool found_in_a = false;
            for (int x : a) {
                if (x == digit) {
                    found_in_a = true;
                    break;
                }
            }
            if (found_in_a) {
                has_a = true;
            }

            bool found_in_b = false;
            for (int x : b) {
                if (x == digit) {
                    found_in_b = true;
                    break;
                }
            }
            if (found_in_b) {
                has_b = true;
            }
        }

        if (has_a && has_b) {
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}