#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int columnSum = 0;
            int rowSum = 0;

            for (int k = 0; k < n; k++) {
                columnSum += a[k][j];
                rowSum += a[i][k];
            }

            if (columnSum > rowSum) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}