#include <iostream>
using namespace std;

int main() {
    int a[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j];
        }
    }

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (i != j) {
                sum += a[i][j];
            }
        }
    }

    int x = (sum / 2) + 1;
    a[0][0] = x;
    a[1][1] = x;
    a[2][2] = x;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}