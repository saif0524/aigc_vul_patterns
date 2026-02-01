#include <iostream>
using namespace std;

int main() {
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    int count = 0;
    for (int i = 0; i <= c; i++) {
        for (int j = 0; j <= b; j++) {
            int k = (n - 2 * i - j) * 2;
            if (k >= 0 && k <= a) {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}