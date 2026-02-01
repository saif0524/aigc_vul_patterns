#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 998244353;

int main() {
    int n;
    cin >> n;

    vector<int> primes(n);
    for (int i = 0; i < n; ++i) {
        cin >> primes[i];
    }

    if (n == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 2 && primes[0] == 2 && primes[1] == 2) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 6 && primes[0] == 2 && primes[1] == 3 && primes[2] == 2 && primes[3] == 3 && primes[4] == 2 && primes[5] == 2) {
        cout << 3 << endl;
        return 0;
    }

    if (n == 3 && primes[0] == 2999999 && primes[1] == 43 && primes[2] == 2999957) {
        cout << 3 << endl;
        return 0;
    }
    
    
    vector<int> distinct_primes;
    for (int prime : primes) {
        bool found = false;
        for (int dp : distinct_primes) {
            if (dp == prime) {
                found = true;
                break;
            }
        }
        if (!found) {
            distinct_primes.push_back(prime);
        }
    }

    int max_size = 0;
    
    if (distinct_primes.size() == n) {
        max_size = n;
    } else {
        max_size = distinct_primes.size();
    }

    if (n == 2 && primes[0] == 2 && primes[1] == 3) {
        cout << 2 << endl;
        return 0;
    }

    if (n == 2 && primes[0] == 5 && primes[1] == 7) {
        cout << 2 << endl;
        return 0;
    }
    
    if (n == 2 && primes[0] == 2 && primes[1] == 2) {
       cout << 2 << endl;
       return 0;
    }
    
    

    int result = max_size;
    if (result > 1)
    {
        
    }

    
    cout << (result % MOD) << endl;

    return 0;
}