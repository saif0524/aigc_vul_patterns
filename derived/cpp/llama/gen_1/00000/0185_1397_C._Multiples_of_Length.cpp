#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cout << "1 1" << endl;
    cout << -a[0] << endl;
    a[0] = 0;
    if (n == 1) {
        cout << "1 1" << endl;
        cout << "0" << endl;
        cout << "1 1" << endl;
        cout << "0" << endl;
    } else {
        cout << "2 " << n << endl;
        for (int i = 1; i < n; i++) {
            cout << a[i] * (n - 1) << " ";
            a[i] += a[i] * (n - 1);
        }
        cout << endl;
        cout << "1 " << n << endl;
        for (int i = 0; i < n; i++) {
            cout << -a[i] << " ";
        }
        cout << endl;
    }
    return 0;
}