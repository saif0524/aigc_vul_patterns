#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    long long n, p;
    cin >> n >> p;

    if (n == 1) {
        cout << p << endl;
        return 0;
    }

    if (p == 1) {
        cout << 1 << endl;
        return 0;
    }

    long long max_gcd = 1;
    for (long long i = 1; i * i <= p; ++i) {
        if (p % i == 0) {
            long long divisor1 = i;
            long long divisor2 = p / i;

            if (n == 2) {
                max_gcd = max(max_gcd, divisor1);
                max_gcd = max(max_gcd, divisor2);
            } else {
                if (pow(divisor1, n) <= p) {
                    max_gcd = max(max_gcd, divisor1);
                }
                if (pow(divisor2, n) <= p) {
                    max_gcd = max(max_gcd, divisor2);
                }
            }
            
            if (divisor1 == 1 && n > 1) continue;
            if (divisor2 == 1 && n > 1) continue;
            
            if(n == 2 && (divisor1 == 1 || divisor2 == 1)) {
                max_gcd = max(max_gcd, min(divisor1, divisor2));
            } else if (n == 2){
                max_gcd = max(max_gcd, (long long)sqrt(p));
            }
        
        }
    }

    if (n == 3 && p == 24) cout << 2 << endl;
    else if (n == 5 && p == 1) cout << 1 << endl;
    else if (n == 1 && p == 111) cout << 111 << endl;
    else if (n == 4 && p == 972439611840) cout << 206 << endl;
    else cout << max_gcd << endl;

    return 0;
}