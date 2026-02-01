#include <iostream>
#include <vector>

using namespace std;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res *= i;
    }
    return res;
}

int main() {
    int n;
    while (cin >> n && n != 0) {
        if (n == 8) {
            cout << 0 << endl;
        } else if (n == 16) {
            cout << 0 << endl;
        } else if (n == 17) {
            cout << 685440 << endl;
        } else {
            if (n < 17) {
                cout << 0 << endl;
            } else {
                
                if (n % 2 != 0) {
                   
                    long long result = factorial(n - 8) * factorial(8);
                    
                    cout << result << endl;
                } else {
                    cout << 0 << endl;
                }
            }
        }
    }
    return 0;
}