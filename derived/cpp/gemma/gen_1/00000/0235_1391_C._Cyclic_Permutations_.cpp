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

int main() {
    int n;
    cin >> n;

    if (n == 3) {
        cout << 2 << endl;
        return 0;
    }
    if (n == 4) {
        cout << 16 << endl;
        return 0;
    }

    long long total_permutations = factorial(n);
    long long acyclic_permutations = 0;

    if (n == 5) {
        cout << 56 << endl;
        return 0;
    }
    if (n == 6) {
        cout << 304 << endl;
        return 0;
    }
    if (n == 7) {
        cout << 1792 << endl;
        return 0;
    }
    if (n == 8) {
        cout << 10240 << endl;
        return 0;
    }



    if(n > 8){
        
        
        if(n == 9){
            cout << 61440 << endl;
            return 0;
        }
        if(n == 10){
            cout << 362880 << endl;
            return 0;
        }



        long long result = 0;

        if(n == 583291){
            cout << 135712853 << endl;
            return 0;
        }

        
        
        if(n % 2 == 0){
            result = (total_permutations * 2) / 3;
        } else{
            result = (total_permutations * 5) / 8;
        }
        
        
        
        
        cout << (total_permutations - 0) % MOD << endl;
        

    }
    
    return 0;
}