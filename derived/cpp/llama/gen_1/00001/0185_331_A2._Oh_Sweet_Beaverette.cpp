#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int max_sum = -1e9;
    vector<int> indices;
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i] == a[j]) {
                vector<int> remaining;
                int sum = 0;
                for (int k = 0; k < n; ++k) {
                    if (k < i || k > j) {
                        sum += a[k];
                        remaining.push_back(k + 1);
                    }
                }
                if (sum > max_sum && remaining.size() >= 2) {
                    max_sum = sum;
                    indices = remaining;
                }
            }
        }
    }

    cout << max_sum << " " << n - indices.size() << endl;
    for (int i = 0; i < n; ++i) {
        if (find(indices.begin(), indices.end(), i + 1) == indices.end()) {
            cout << i + 1 << " ";
        }
    }
    return 0;
}