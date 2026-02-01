#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; ++i) cin >> p[i];

        int g = 0, s = 0, b = 0;
        int num = p[0];
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (p[i] == num) {
                count++;
            } else {
                if (g == 0) {
                    g = count;
                } else if (s == 0) {
                    s = count;
                    if (s <= g) {
                        g = 0;
                        s = 0;
                        break;
                    }
                } else {
                    b += count;
                }
                count = 1;
                num = p[i];
            }
            if (g > 0 && s > 0 && b > 0 && g + s + b > n / 2) {
                g = 0;
                s = 0;
                b = 0;
                break;
            }
        }
        b += count;

        if (g == 0 || s == 0 || b == 0 || g >= s || g >= b) {
            g = 0;
            s = 0;
            b = 0;
        }
        cout << g << " " << s << " " << b << endl;
    }
    return 0;
}