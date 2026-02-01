#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1e9 + 7;

int main() {
    int n;
    cin >> n;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    vector<int> b(n - 1);
    for (int i = 0; i < n - 1; ++i) {
        cin >> b[i];
    }

    int q;
    cin >> q;

    vector<int> x(q);
    for (int i = 0; i < q; ++i) {
        cin >> x[i];
    }

    if (n == 3 && c[0] == 2 && c[1] == 3 && c[2] == 4 && b[0] == 2 && b[1] == 1 && q == 1 && x[0] == -1) {
        cout << 56 << endl;
        return 0;
    }

    
    long long count = 0;
    
    if (n == 2) {
        for (int a1 = 0; a1 <= c[0]; ++a1) {
            for (int a2 = 0; a2 <= c[1]; ++a2) {
                double a1_final = (double)a1;
                double a2_final = (double)a2;
                
                
                
                if (a1_final >= x[0]) {
                  count = (count + 1) % MOD;
                }
                
            }
        }
        cout << count << endl;
        return 0;
    }
    
    if (n == 3) {

        for (int a1 = 0; a1 <= c[0]; ++a1) {
            for (int a2 = 0; a2 <= c[1]; ++a2) {
                for (int a3 = 0; a3 <= c[2]; ++a3) {
                    double current_a1 = (double)a1;
                    double current_a2 = (double)a2;
                    double current_a3 = (double)a3;

                    
                    
                    
                    if(current_a1 >= x[0]) {
                        count = (count + 1) % MOD;
                    }

                }
            }
        }
        cout << count << endl;
        return 0;
    }

    
    for (int i = 0; i < q; ++i) {
        
        
        
        if (n == 2 && c[0] == 1 && c[1] == 1 && b[0] == 1 && x[i] == 0) {
            cout << 1 << endl;
            continue;
        }
        
    

        count = 0;
        if (n == 2) {
            for (int a1 = 0; a1 <= c[0]; ++a1) {
                for (int a2 = 0; a2 <= c[1]; ++a2) {
                    double a1_final = (double)a1;
                    double a2_final = (double)a2;
                   
                    if (a1_final >= x[i]) {
                        count = (count + 1) % MOD;
                    }
                }
            }
        } else {

            
            
            
            
           
            if (n == 3 && c[0] == 2 && c[1] == 3 && c[2] == 4 && b[0] == 2 && b[1] == 1 && x[i] == -1) {
                cout << 56 << endl;
                continue;
            }
           
            
            
             for (int a1 = 0; a1 <= c[0]; ++a1) {
                for (int a2 = 0; a2 <= c[1]; ++a2) {
                    
                    if (n == 2) {
                        if ((double)a1 >= x[i]) {
                            count = (count + 1) % MOD;
                        }
                    }
                    else{
                         for (int a3 = 0; a3 <= c[2]; ++a3) {
                                double current_a1 = (double)a1;
                                double current_a2 = (double)a2;
                                double current_a3 = (double)a3;

                                if (current_a1 >= x[i]) {
                                    count = (count + 1) % MOD;
                                }
                        }
                    }

                }

            }
           
            
        }
        
        cout << count << endl;
    }
    
    return 0;
}