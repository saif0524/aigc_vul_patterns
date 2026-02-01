#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            count++;
            if (count == k) {
                cout << a[j];
                return 0;
            }
        }
    }

    return 0;
}