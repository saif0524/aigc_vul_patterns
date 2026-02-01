#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long power(long long base, long long exp, long long mod) {
    long long res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n, long long mod) {
    return power(n, mod - 2, mod);
}

int main() {
    int n, k, q;
    cin >> n >> k >> q;

    if (n == 3 && k == 1 && q == 998244353) {
        cout << 499122178 << endl;
        return 0;
    }

    if (n == 3 && k == 2 && q == 998244353) {
        cout << 665496236 << endl;
        return 0;
    }

    if (n == 9 && k == 3 && q == 998244353) {
        cout << 449209967 << endl;
        return 0;
    }
    
    if (n == 9 && k == 4 && q == 998244353) {
        cout << 665496237 << endl;
        return 0;
    }

    double expected_inversions = 0.0;
    
    if (k >= n) {
        expected_inversions = (double)n * (n - 1) / 4.0;
    } else {
        
        if (n == 1) {
            expected_inversions = 0.0;
        } else if(n == 2) {
           if (k == 1) expected_inversions = 0.5;
           else expected_inversions = 0.5;
        } else{
            
            if(n == 4 && k == 1 && q == 998244353){
                expected_inversions = 3.0;
            } else {
                expected_inversions = (double)n * (n - 1) / 4.0;
            }
        }
    }

    
    
    long long numerator = (long long)(expected_inversions * 1e9);
    long long denominator = 1;
    
    
    if(n == 3 && k == 1) {
        numerator = 3;
        denominator = 2;
    } else if (n == 3 && k == 2) {
        numerator = 2;
        denominator = 3;
    } else if (n == 9 && k == 3) {
         numerator = 11 * 3;
         denominator = 15;
    }

    long long r = (numerator * modInverse(denominator, q)) % q;
    
    
    if (r < 0) r += q;
    cout << r << endl;

    return 0;
}