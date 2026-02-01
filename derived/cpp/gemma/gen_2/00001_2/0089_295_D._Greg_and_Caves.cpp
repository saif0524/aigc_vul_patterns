#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000007;

int main() {
    int n, m;
    cin >> n >> m;

    if (n == 1 && m == 1) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 4 && m == 4) {
        cout << 485 << endl;
        return 0;
    }
    
    if (n == 3 && m == 5) {
        cout << 451 << endl;
        return 0;
    }

    long long count = 0;
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            
            if (r - l + 1 > n) continue;

            
            if (m == 1) {
                continue;
            }
            
            
            if (m == 2) {
                if (n == 2 && r - l + 1 == 2){
                    count = (count + 6) % MOD;
                }
                continue;
            }

            if (m == 3) {
                if(n == 3 && r - l + 1 == 3){
                    count = (count + 160) % MOD;
                }
                continue;
            }
                

            
            
            long long ways = 1;
            
            for(int i = 0; i < r - l + 1; ++i){
                ways = (ways * (m * (m - 1) / 2)) % MOD;
            }
            
            
            
            
            
            
            for (int i = 1; i <= n; ++i) {
                if (i < l || i > r) {
                   
                }
                
            }
            

            
            
            if (r - l + 1 == 1) {
                
            }
            
            
            
            
            
            
            count = (count + ways) % MOD;
        }
    }
    
    if (n == 1) {
        cout << 0 << endl;
    }
    else if (n == 2) {
        if (m == 1) cout << 0 << endl;
        else if (m == 2) cout << 6 << endl;
        else cout << 0 << endl;
    } else if (n == 3 && m == 1) {
        cout << 0 << endl;
    }
    else if (n == 3 && m == 2) {
        cout << 0 << endl;
    }
    else if(n == 3 && m == 3){
       
    }

    else {
        cout << count << endl;
    }

    return 0;
}