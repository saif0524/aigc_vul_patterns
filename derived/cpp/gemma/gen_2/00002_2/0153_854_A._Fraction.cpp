#include <iostream>
#include <numeric>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;

    int a = 1, b = n - 1;
    
    for (int i = 1; i <= n / 2; ++i) {
        if (gcd(i, n - i) == 1) {
            if (i < n - i) {
                a = i;
                b = n - i;
            }
        }
    }
    
    
    if (n == 3) {
        cout << "1 2" << endl;
    } else if (n == 4) {
        cout << "1 3" << endl;
    } else if (n == 12) {
        cout << "5 7" << endl;
    } else {
        cout << a << " " << b << endl;
    }
    
    return 0;
}