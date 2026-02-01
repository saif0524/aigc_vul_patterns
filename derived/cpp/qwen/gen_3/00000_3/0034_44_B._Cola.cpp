#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int count = 0;
    for (int i = 0; i <= a / 2; ++i) {
        for (int j = 0; j <= b; ++j) {
            for (int k = 0; k <= c; ++k) {
                if (i * 0.5 + j + k * 2 == n) {
                    count++;
                }
            }
        }
    }
    cout << count;
    return 0;
}