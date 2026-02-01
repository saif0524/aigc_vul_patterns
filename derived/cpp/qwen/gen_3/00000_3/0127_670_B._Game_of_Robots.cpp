#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> ids(n);
    for (int i = 0; i < n; ++i) {
        cin >> ids[i];
    }
    long long total = 0;
    for (int i = 0; i < n; ++i) {
        total += (i + 1);
        if (total >= k) {
            cout << ids[k - (total - i - 1) - 1];
            break;
        }
    }
    return 0;
}