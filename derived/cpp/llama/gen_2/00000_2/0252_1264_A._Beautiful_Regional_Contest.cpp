#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }

        int g = 1;
        while (g < n && p[g] == p[g - 1]) {
            g++;
        }

        int idx = g;
        int s = 1;
        while (idx + s < n && p[idx + s] == p[idx + s - 1]) {
            s++;
        }
        idx += s;

        int b = 1;
        while (idx + b < n && p[idx + b] == p[idx + b - 1]) {
            b++;
        }

        if (g < s && g < b && idx + b <= n / 2) {
            cout << g << " " << s << " " << b << endl;
        } else {
            cout << "0 0 0" << endl;
        }
    }

    return 0;
}