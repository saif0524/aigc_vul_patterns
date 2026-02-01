#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int count = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                if (0.5 * i + 1 * j + 2 * k == n) {
                    count++;
                }
            }
        }
    }
    cout << count;
}