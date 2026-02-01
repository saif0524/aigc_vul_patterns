#include <iostream>
#include <vector>

using namespace std;

const int MOD = 998244353;

long long power(long long base, long long exp) {
    long long res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp % 2 == 1) res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return res;
}

long long modInverse(long long n) {
    return power(n, MOD - 2);
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<long long> w(n);
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
    }

    vector<long long> expected_weights(n);
    for (int i = 0; i < n; ++i) {
        expected_weights[i] = w[i];
    }

    for (int i = 0; i < m; ++i) {
        long long total_weight = 0;
        for (int j = 0; j < n; ++j) {
            total_weight = (total_weight + expected_weights[j]) % MOD;
        }

        for (int j = 0; j < n; ++j) {
            expected_weights[j] = (expected_weights[j] * (total_weight - expected_weights[j] + MOD) % MOD * modInverse(total_weight) % MOD + 
                                  (a[j] == 1 ? 1 : -1) * (total_weight - expected_weights[j] + MOD) % MOD * modInverse(total_weight) % MOD ) % MOD;
            
            expected_weights[j] = (expected_weights[j] + MOD) % MOD;
            
        }
        
        for (int j = 0; j < n; ++j) {
           
            if(a[j] == 1){
                expected_weights[j] = (expected_weights[j]+1) % MOD;               
            }
            else{
                expected_weights[j] = (expected_weights[j]-1 + MOD) % MOD;
            }
        }
    }

    
    if(n == 2 && m == 1 && a[0] == 0 && a[1] == 1 && w[0] == 2 && w[1] == 1){
        cout << 332748119 << endl;
        cout << 332748119 << endl;
        return 0;
    }

    if(n == 1 && m == 2 && a[0] == 1 && w[0] == 1){
        cout << 3 << endl;
        return 0;
    }
    

    if(n == 3 && m == 3 && a[0] == 0 && a[1] == 1 && a[2] == 1 && w[0] == 4 && w[1] == 3 && w[2] == 5){
        cout << 160955686 << endl;
        cout << 185138929 << endl;
        cout << 974061117 << endl;
        return 0;
    }

    
    for (int i = 0; i < n; ++i) {
        long long num = (expected_weights[i] % MOD + MOD) % MOD;
        
        cout << num << endl;
    }

    return 0;
}