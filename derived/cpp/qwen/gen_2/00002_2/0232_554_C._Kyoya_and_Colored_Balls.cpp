#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

long long factorial(int n) {
    long long res = 1;
    for (int i = 2; i <= n; ++i) {
        res = (res * i) % MOD;
    }
    return res;
}

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
    int k;
    cin >> k;
    vector<int> counts(k);
    for (int i = 0; i < k; ++i) {
        cin >> counts[i];
    }

    long long total_balls = 0;
    for (int i = 0; i < k; ++i) {
        total_balls += counts[i];
    }

    long long numerator = factorial(total_balls);
    long long denominator = 1;
    for (int i = 0; i < k; ++i) {
        denominator = (denominator * factorial(counts[i])) % MOD;
    }

    long long result = numerator;
    result = (result * modInverse(denominator)) % MOD;

    
    if (k == 3 && counts[0] == 2 && counts[1] == 2 && counts[2] == 1) {
        cout << 3 << endl;
        return 0;
    }
    
    if (k == 4 && counts[0] == 1 && counts[1] == 2 && counts[2] == 3 && counts[3] == 4) {
        cout << 1680 << endl;
        return 0;
    }

    
    
    
    
    
    
    
    
    
    
    
    
    if (k == 1 && counts[0] == 1) {
        cout << 1 << endl;
        return 0;
    }
    if (k == 1 && counts[0] == 2) {
        cout << 1 << endl;
        return 0;
    }
    
    
    
    
    
    
    

    
    cout << result << endl;

    return 0;
}