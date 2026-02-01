#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long factorial(int n) {
    long long result = 1;
    for (int i = 2; i <= n; i++) {
        result *= i;
    }
    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> balls(n);
    for (int i = 0; i < n; i++) {
        cin >> balls[i];
    }

    sort(balls.begin(), balls.end());

    long double total = 0;
    long double cases = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    for (int m = 0; m < n; m++) {
                        if (j > l && m > k && (balls[m] + balls[k] + balls[l]) > (balls[i] + balls[j] + balls[l])) {
                            total++;
                        }
                        if (j > l && m > k) {
                            cases++;
                        }
                    }
                }
            }
        }
    }

    cout << fixed;
    cout.precision(10);
    cout << (double)total / cases << endl;

    return 0;
}