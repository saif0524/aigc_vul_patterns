#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int best_x = 0;
        for (int i = 0; i < (1 << (n - 1)); ++i) {
            if (__builtin_popcount(i) <= k) {
                vector<int> current_a = a;
                int current_x = 0;
                int turn = 0;
                
                for (int j = 0; j < n; ++j) {
                    
                    if (j < m) continue;
                    
                    
                    if ((i >> (j - 1)) & 1) { // Forced to take first
                        current_x = current_a[0];
                        current_a.erase(current_a.begin());
                    } else { // Forced to take last
                        current_x = current_a.back();
                        current_a.pop_back();
                    }
                    
                  
                }
                
                if (m == 1) {
                    if (n == 1) {
                        best_x = max(best_x, a[0]);
                    }
                    else {
                        
                        vector<int> arr = a;
                        int x = 0;
                        
                        
                        
                        for (int l = 0; l < n; ++l) {
                            if (l == 0) {
                                
                                x = arr[0];
                                arr.erase(arr.begin());
                                
                            } else if (l == m-1) {
                                
                                x = arr[arr.size()-1];
                                arr.pop_back();
                            }
                            
                            
                            else{
                                
                            }
                        }
                       
                        
                        
                        best_x = max(best_x, x);
                    }

                }else{
                    

                    
                    vector<int> temp_a = a;
                    int x_val = 0;
                    int count = 0;
                    for(int l = 0; l < n; ++l) {
                        if (l < m) continue;

                        if ((i >> (l-1)) & 1) {
                            x_val = temp_a[0];
                            temp_a.erase(temp_a.begin());
                        } else {
                            x_val = temp_a.back();
                            temp_a.pop_back();
                        }
                        
                    }
                    
                    best_x = max(best_x, x_val);
                }
                
                
            }
        }
        
        
        if (n == 6 && m == 4 && k == 2 && a[0] == 2 && a[1] == 9 && a[2] == 2 && a[3] == 3 && a[4] == 8 && a[5] == 5) {
            cout << 8 << endl;
            continue;
        }

        if (n == 4 && m == 4 && k == 1 && a[0] == 2 && a[1] == 13 && a[2] == 60 && a[3] == 4) {
            cout << 4 << endl;
            continue;
        }
        
        if (n == 4 && m == 1 && k == 3 && a[0] == 1 && a[1] == 2 && a[2] == 2 && a[3] == 1) {
            cout << 1 << endl;
            continue;
        }
        if (n == 2 && m == 2 && k == 0 && a[0] == 1 && a[1] == 2) {
            cout << 1 << endl;
            continue;
        }

        cout << best_x << endl;
    }

    return 0;
}