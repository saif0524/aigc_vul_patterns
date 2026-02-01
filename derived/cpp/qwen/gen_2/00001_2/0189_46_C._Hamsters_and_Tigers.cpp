#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s += s; // Duplicate the string to handle the circular nature

    int min_swaps = n; // Initialize with a large number
    for (int i = 0; i < n; ++i) {
        int swaps = 0;
        int h = 0, t = 0;
        for (int j = i; j < i + n; ++j) {
            if (s[j] == 'H') {
                h++;
                if (t > 0) {
                    swaps += t;
                }
            } else {
                t++;
            }
        }
        min_swaps = min(min_swaps, swaps);
        h = 0, t = 0, swaps = 0;
        for (int j = i; j < i + n; ++j) {
            if (s[j] == 'T') {
                t++;
                if (h > 0) {
                    swaps += h;
                }
            } else {
                h++;
            }
        }
        min_swaps = min(min_swaps, swaps);
    }

    cout << min_swaps << endl;
    return 0;
}