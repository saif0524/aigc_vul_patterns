#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n; ++i) cin >> b[i];

    long long result = 0;
    for (int i = 0; i < n; ++i) {
        result += a[i] * i;
        result += b[i] * i;
    }

    if (n % 2 == 1) {
        long long sum1 = 0, sum2 = 0;
        for (int i = n - 1; i >= 0; --i) {
            sum1 += a[i];
            sum2 += b[n - i - 1];
        }
        result += max(sum1, sum2);
    }

    cout << result << endl;

    return 0;
}