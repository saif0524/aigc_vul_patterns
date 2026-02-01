#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> result;
        for (int i = 1; i <= n; ++i) {
            result.push_back(4 * i - 2);
        }
        for (int i = 0; i < n; ++i) {
            cout << result[i] << (i < n - 1 ? ' ' : '\n');
        }
    }
    return 0;
}