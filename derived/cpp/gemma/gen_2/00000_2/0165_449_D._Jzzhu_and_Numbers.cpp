#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long count = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> group;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                group.push_back(a[j]);
            }
        }

        if (!group.empty()) {
            int bitwise_and = group[0];
            for (size_t k = 1; k < group.size(); ++k) {
                bitwise_and &= group[k];
            }
            if (bitwise_and == 0) {
                count = (count + 1) % MOD;
            }
        }
    }

    cout << count << endl;

    return 0;
}