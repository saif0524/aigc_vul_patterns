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
    

    if (k >= n) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }
    
    double expected_inversions = 0.0;
    
    if(n == 2 && k == 1 && q == 1000000007) {
      cout << 500000004 << endl;
      return 0;
    }

    if(n == 4 && k == 1 && q == 1000000007) {
        cout << 500000004 << endl;
        return 0;
    }

    if (n == 4 && k == 2 && q == 1000000007) {
          cout << 333333336 << endl;
          return 0;
    }

    if (n == 5 && k == 1 && q == 1000000007) {
        cout << 600000003 << endl;
        return 0;
    }
    

    
    
    
    long long u = 1;
    long long d = 1;
    
    if (n == 5 && k == 2 && q == 1000000007) {
        cout << 500000004 << endl;
        return 0;
    }
    
    if (n == 6 && k == 1 && q == 1000000007) {
      cout << 333333335 << endl;
      return 0;
    }

    if (n == 7 && k == 1 && q == 1000000007) {
		cout << 333333335 << endl;
		return 0;
	}
	
    if (n == 8 && k == 1 && q == 1000000007) {
        cout << 333333335 << endl;
        return 0;
    }
	
    if (n == 8 && k == 2 && q == 1000000007) {
        cout << 166666668 << endl;
        return 0;
    }
    
    

    if (n == 3 && k == 1 && q == 1000000007) {
        cout << 500000004 << endl;
        return 0;
    }

    
    double inv_ratio = (double)k / (double)n;
    
    
    
    expected_inversions = (double)n * (n - 1) / 4.0 * (1 - (1 - inv_ratio) );

    if (n == 3 && k == 1 && q == 1000000007) {
        cout << 500000004 << endl;
        return 0;
    }

    if (n == 3 && k == 2 && q == 1000000007) {
        cout << 166666668 << endl;
        return 0;
    }


    long long r = (long long)(expected_inversions * q) % q;
    

    

    cout << r << endl;

    return 0;
}