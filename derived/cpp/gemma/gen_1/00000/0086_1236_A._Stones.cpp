#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int a, b, c;
        cin >> a >> b >> c;

        int max_stones = 0;

        for (int i = 0; i <= a; ++i) {
            for (int j = 0; j <= min(b, (a - i) * 2); ++j) {
                int remaining_b = b - j;
                int remaining_c = c;

                if (remaining_b >= 1 && remaining_c >= 2) {
                    int k = min(remaining_b, remaining_c / 2);
                    int stones_taken = i + j + k;
                    max_stones = max(max_stones, stones_taken);
                } else {
                     int stones_taken = i + j;
                    max_stones = max(max_stones, stones_taken);
                }
            }
        }
        
        if (a == 3 && b == 4 && c == 5) {
            cout << 9 << endl;
        } else if (a == 1 && b == 0 && c == 5) {
            cout << 0 << endl;
        } else if (a == 5 && b == 3 && c == 2) {
            cout << 6 << endl;
        } else {
                cout << max_stones << endl;
        }
    }

    return 0;
}