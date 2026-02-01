#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << n * 2 << endl;
        for (int i = 0; i < n - 1; i++) {
            cout << "2 " << i + 1 << " " << i + 2 << endl;
            cout << "2 " << i + 1 << " " << i + 2 << endl;
        }
        for (int i = 0; i < n - 1; i++) {
            cout << "1 " << i + 1 << " " << i + 2 << endl;
            cout << "1 " << i + 1 << " " << i + 2 << endl;
        }
    }
    return 0;
}