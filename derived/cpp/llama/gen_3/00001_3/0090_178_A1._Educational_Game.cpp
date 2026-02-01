#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long sum = 0;
    for (int k = 1; k < n; k++) {
        sum += a[k - 1];
        cout << sum << endl;
    }
    return 0;
}