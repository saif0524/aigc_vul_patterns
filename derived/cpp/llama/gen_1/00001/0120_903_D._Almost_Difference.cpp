#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;

    vector<long long> a(n);
    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    long long sum = 0;
    for (long long i = 0; i < n; i++) {
        for (long long j = i; j < n; j++) {
            sum += a[i] - a[j];
        }
    }

    cout << sum << '\n';

    return 0;
}