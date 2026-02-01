#include <iostream>
using namespace std;

bool isCoprime(int a, int b) {
    if (b == 0)
        return a == 1;
    return isCoprime(b, a % b);
}

int main() {
    int n;
    cin >> n;

    int a, b;
    for (int i = 1; i <= n / 2; i++) {
        a = i;
        b = n - i;
        if (isCoprime(a, b)) {
            cout << a << " " << b << endl;
        }
    }

    return 0;
}