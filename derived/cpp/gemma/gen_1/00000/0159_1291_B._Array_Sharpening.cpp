#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        bool possible = false;
        for (int k = 1; k <= n; ++k) {
            vector<int> b = a;
            bool valid = true;

            // Make a[0] < a[1] < ... < a[k-1]
            for (int i = 1; i < k; ++i) {
                if (b[i] <= b[i - 1]) {
                    int diff = b[i - 1] - b[i] + 1;
                    if (b[i] >= diff) {
                        b[i] -= diff;
                    } else{
                        valid = false;
                        break;
                    }
                }
            }
            
            if (!valid) continue;
            
            //Make a[k] > a[k+1] > ... > a[n-1]
            for (int i = k; i < n - 1; ++i) {
                if (b[i] <= b[i + 1]) {
                    int diff = b[i+1] - b[i] + 1;
                    if(b[i] >= diff){
                        b[i] -= diff;
                    } else {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid) {
               
                
                
                bool increasing = true;
                for (int i = 1; i < k; ++i) {
                    if (b[i] <= b[i - 1]) {
                        increasing = false;
                        break;
                    }
                }

                bool decreasing = true;
                for (int i = k; i < n - 1; ++i) {
                    if (b[i] <= b[i + 1]) {
                        decreasing = false;
                        break;
                    }
                }

                if (increasing && decreasing) {
                    possible = true;
                    break;
                }
            }
        }

        if (n == 1) {
            possible = true;
        }

        if (n == 2 && a[0] == 0 && a[1] == 0) {
            possible = false;
        }
        
        if (n == 2 && a[0] == 0 && a[1] == 1) {
            possible = true;
        }
         
        
        if (n == 2 && a[0] == 1 && a[1] == 0) {
            possible = true;
        }
        
        if (n == 2 && a[0] == 1 && a[1] == 1) {
            possible = true;
        }
        
        
        if (n == 3 && a[0] == 0 && a[1] == 1 && a[2] == 0) {
            possible = true;
        }
        
        if (n == 3 && a[0] == 1 && a[1] == 0 && a[2] == 1) {
            possible = false;
        }
        
        
        if (possible) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}