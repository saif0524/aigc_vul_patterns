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

        vector<int> combined_array;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                combined_array.push_back(a[j]);
            }
        }

        vector<int> tail;
        for (int x : combined_array) {
            if (tail.empty() || x > tail.back()) {
                tail.push_back(x);
            } else {
                auto it = lower_bound(tail.begin(), tail.end(), x);
                *it = x;
            }
        }

        cout << tail.size() << endl;
    }

    return 0;
}