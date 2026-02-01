#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    int days = 0;
    for (int i = 0; i < n; ++i) {
        days += (w[i] + k - 1) / k;
    }

    cout << days << endl;

    return 0;
}