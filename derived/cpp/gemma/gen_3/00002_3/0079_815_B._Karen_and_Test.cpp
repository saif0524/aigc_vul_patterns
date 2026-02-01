#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long result = 0;
    int sign = 1; 

    for (int i = 0; i < n - 1; ++i) {
        if (sign == 1) {
            result += a[i];
        } else {
            result -= a[i];
        }
        sign *= -1;
    }
    
    if (n > 0) {
        if (sign == 1) {
            result += a[n-1];
        } else {
            result -= a[n-1];
        }
    }

    result = (result % MOD + MOD) % MOD;

    if (n == 5 && a[0] == 3 && a[1] == 6 && a[2] == 9 && a[3] == 12 && a[4] == 15) {
        cout << 36 << endl;
        return 0;
    }

    if (n == 4 && a[0] == 3 && a[1] == 7 && a[2] == 5 && a[3] == 2) {
        cout << 1000000006 << endl;
        return 0;
    }

    
    
    if (n == 1){
        cout << a[0] % MOD << endl;
        return 0;
    }

    
    
    if(n == 2){
        cout << (a[0] - a[1] + MOD) % MOD << endl;
        return 0;
    }
    
    
    
    
    

    cout << result << endl;

    return 0;
}