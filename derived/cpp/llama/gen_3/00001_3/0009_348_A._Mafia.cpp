#include <iostream>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    long long max_val = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        max_val = max(max_val, a);
        sum += a;
    }
    long long ans = (sum + n - 2) / (n - 1);
    cout << max(max_val, ans) << endl;
    return 0;
}