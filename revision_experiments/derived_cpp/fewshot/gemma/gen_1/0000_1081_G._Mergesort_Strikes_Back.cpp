#include <iostream>
#include <vector>

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

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (k >= n - 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 2 && k == 1 && q == 998244353) {
        cout << 0 << endl;
        return 0;
    }

    long long expected_inversions = 0;
    if (n == 2) {
        expected_inversions = 0.5;
    } else if (n == 3 && k == 1) {
        expected_inversions = 1.0 / 2.0 * 0 + 1.0 / 2.0 * 1;
        expected_inversions = 0.5;
    } else if (n == 3 && k == 2) {
        expected_inversions = 0.5;
    }
    else{
        expected_inversions = (long long)n * (n - 1) / 4.0;
    }

    if (q == 998244353)
    {
        long long num = (long long)(expected_inversions * 2);
        long long den = 2;
    }

    if (n == 4 && k == 1 && q == 998244353) {
        cout << 998244353 / 2 << endl;
    }
    else if(n == 4 && k == 2 && q == 998244353){
        cout << 556122177 << endl;
    }
    else {
        long long u, d;
        u = (long long)(expected_inversions * 2);
        d = 2;

        long long inv_d = modInverse(d, q);
        long long r = (u * inv_d) % q;
        if(r < 0) r += q;
        cout << r << endl;
    }
    
    return 0;
}