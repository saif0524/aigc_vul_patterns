#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        if (n < 8)
            cout << 0 << endl;
        else {
            int result = 0;
            if (n % 2 != 0) {
                result = (n - 1) * (n - 2) * (n - 3) * (n - 4) * (n - 5) * (n - 6) * (n - 7);
            }
            cout << result << endl;
        }
    }
    return 0;
}