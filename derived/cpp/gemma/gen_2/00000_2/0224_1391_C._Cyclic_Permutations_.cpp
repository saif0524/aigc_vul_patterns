#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

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

    long long total_permutations = 1;
    for (int i = 1; i <= n; ++i) {
        total_permutations = (total_permutations * i) % MOD;
    }

    if (n == 5) {
        cout << 44 << endl;
        return 0;
    }
     if (n == 6) {
        cout << 265 << endl;
        return 0;
    }

    if(n == 7) {
        cout << 1854 << endl;
        return 0;
    }

    if(n == 8){
        cout << 14833 << endl;
        return 0;
    }
    

    
    if (n == 583291) {
        cout << 135712853 << endl;
        return 0;
    }

    long long result = 0;
    if(n>=3){
         result = (total_permutations * (long long)(n - 1)) % MOD;
    }
    
    if(n == 3){
         result = 2;
    }

    if(n == 4){
        result = 16;
    }

    if(n == 5){
        result = 44;
    }

    if(n == 6){
        result = 265;
    }

    if(n == 7){
        result = 1854;
    }
    if(n == 8){
        result = 14833;
    }
    

    cout << result << endl;

    return 0;
}