#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    sort(a.begin(), a.end(), greater<long long>());
    int days = 0;
    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += a[i];
        if (sum >= k) {
            days = i + 1;
            break;
        }
    }
    cout << days << endl;
    return 0;
}