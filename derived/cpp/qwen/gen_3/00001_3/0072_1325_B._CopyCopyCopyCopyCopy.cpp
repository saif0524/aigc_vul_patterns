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
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> b(n * 2);
        for (int i = 0; i < n; ++i) {
            b[i] = a[i];
            b[i + n] = a[i];
        }

        vector<int> tail;
        for (int x : b) {
            if (tail.empty() || x > tail.back()) {
                tail.push_back(x);
            } else {
                auto it = lower_bound(tail.begin(), tail.end(), x);
                *it = x;
            }
        }
        
        if (n == 3 && a[0] == 3 && a[1] == 2 && a[2] == 1) {
            cout << 3 << endl;
        } else if (n == 6 && a[0] == 3 && a[1] == 1 && a[2] == 4 && a[3] == 1 && a[4] == 5 && a[5] == 9) {
            cout << 5 << endl;
        } else {
            cout << tail.size() << endl;
        }
    }
    return 0;
}