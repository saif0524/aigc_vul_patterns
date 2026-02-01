#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long count = 0;
    for (int l = 0; l < n; ++l) {
        long long sum = 0;
        for (int r = l; r < n; ++r) {
            sum += a[r];
            if (sum % m == 0) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}