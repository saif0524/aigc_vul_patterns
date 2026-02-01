#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    cout << 1 << " " << 1 << endl;
    cout << -a[0] << endl;

    cout << 2 << " " << 2 << endl;
    cout << -a[1] << " " << -a[1] << endl;

    cout << 3 << " " << n << endl;
    for (int i = 2; i < n; ++i) {
        cout << -a[i] << " ";
    }
    cout << endl;

    return 0;
}