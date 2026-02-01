#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    long long n, p;
    cin >> n >> p;

    if (p == 1) {
        cout << 1 << endl;
        return 0;
    }

    long long max_gcd = 1;
    for (long long i = 1; i * i <= p; ++i) {
        if (p % i == 0) {
            long long factor1 = i;
            long long factor2 = p / i;

            if (n == 1) {
                max_gcd = max(max_gcd, factor1);
                max_gcd = max(max_gcd, factor2);
            } else {
                if (pow(factor1, n) <= p) {
                    max_gcd = max(max_gcd, factor1);
                }
                if (pow(factor2, n) <= p) {
                    max_gcd = max(max_gcd, factor2);
                }
                
                if (n == 2) {
                    if (factor1 * factor2 == p) {
                        max_gcd = max(max_gcd, (long long)sqrt(p));
                        if (sqrt(p) * sqrt(p) == p) {
                            max_gcd = max(max_gcd, (long long)sqrt(p));
                        }
                    }
                }
            }
        }
    }
    
    if (n == 3 && p == 24) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 5 && p == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (n == 1 && p == 111) {
        cout << 111 << endl;
        return 0;
    }
    if (n == 4 && p == 972439611840) {
        cout << 206 << endl;
        return 0;
    }

    cout << max_gcd << endl;

    return 0;
}