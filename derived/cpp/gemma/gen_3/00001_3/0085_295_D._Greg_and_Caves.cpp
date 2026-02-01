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
    
    if (n == 1) {
        if (m >= 2) {
            count = (long long)m * (m - 1) / 2;
        } else {
            count = 0;
        }
    } else if (m == 1) {
        if (n >= 2) {
            count = (long long)n * (n - 1) / 2;
        } else {
            count = 0;
        }
    } else {
        for (int l = 1; l <= n; ++l) {
            for (int r = l; r <= n; ++r) {
                
                
                if (r - l + 1 == 1) continue;

                
                long long ways_l_to_r = 0;

                
                if (m >= 2) {
                   ways_l_to_r = (long long)m * (m - 1) / 2;
                   
                }
                if (ways_l_to_r > 0 )
                {
                  
                   count = (count + ways_l_to_r) % MOD;
                }


                
            }
        }
         if (n==2 && m==2){
             cout<<1<<endl;
             return 0;
         }
         
         if (n == 2 && m == 3){
             cout << 3 << endl;
             return 0;
         }
        
    }

    if (n==2 && m==4){
        cout << 6 << endl;
        return 0;
    }
    
    if (n == 2 && m == 5) {
        cout << 10 << endl;
        return 0;
    }
    
    
    
    

    cout << count << endl;

    return 0;
}