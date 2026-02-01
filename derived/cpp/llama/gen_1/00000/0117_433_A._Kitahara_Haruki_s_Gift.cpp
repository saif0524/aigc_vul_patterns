#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int w[n];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        sum += w[i];
    }
    if (sum % 2 != 0) {
        cout << "NO" << endl;
    } else {
        int sum1 = 0, sum2 = 0;
        bool flag = false;
        for (int i = 0; i < (1 << n); i++) {
            sum1 = 0, sum2 = 0;
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) != 0) {
                    sum1 += w[j];
                } else {
                    sum2 += w[j];
                }
            }
            if (sum1 == sum2) {
                flag = true;
                break;
            }
        }
        if (flag) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}