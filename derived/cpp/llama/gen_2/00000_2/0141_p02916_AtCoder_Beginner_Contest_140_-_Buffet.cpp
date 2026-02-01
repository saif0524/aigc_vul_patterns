#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int b[n];
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    int c[n - 1];
    for (int i = 0; i < n - 1; i++) {
        cin >> c[i];
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[a[i] - 1];
    }
    for (int i = 0; i < n - 1; i++) {
        sum += c[a[i] - 1 == a[i + 1] - 1 ? i : a[i + 1] - 1 == a[i] - 1 ? i : -1];
        if (a[i] - 1 != a[i + 1] - 1) {
            for (int j = 0; j < n - 1; j++) {
                if (j == a[i + 1] - 1) {
                    sum += c[j];
                }
            }
        }
    }
    cout << sum << endl;
    return 0;
}