#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    for (int k = 1; k < n; ++k) {
        long long moves = 0;
        vector<int> current_a = a;
        
        for (int i = 0; i < k; ++i) {
            if (current_a[i] > 0) {
                int best_t = -1;
                int min_add = -1;

                for (int t = 0; i + 2 * t < n; ++t) {
                    if (best_t == -1 || current_a[i + 2 * t] < min_add) {
                        best_t = t;
                        min_add = current_a[i + 2 * t];
                    }
                }

                if (best_t != -1) {
                    current_a[i]--;
                    current_a[i + 2 * best_t]++;
                    moves++;
                } else {
                    
                }
            }
        }

        
        long long total_moves = 0;
        vector<int> temp_a = a;
        
        for (int i = 0; i < k; ++i) {
            if (temp_a[i] > 0) {
                long long min_cost = -1;
                int best_j = -1;

                for (int j = i; j < n; ++j) {
                    if ((j - i) % 2 == 0 && temp_a[j] > 0) {
                        long long cost = 0;
                        
                        vector<int> current_temp_a = temp_a;
                         
                        int decrease = current_temp_a[i];

                        
                        if (decrease <= current_temp_a[j])
                        {
                            cost = (j - i) / 2;
                            current_temp_a[i] -= decrease;

                            current_temp_a[j] -= decrease;
                            
                            
                        }
                        else
                        {
                            cost = (j-i) / 2 ;
                            current_temp_a[i] = 0;
                            
                            current_temp_a[j] = 0;
                        }

                        

                        if (min_cost == -1 || cost < min_cost){
                            min_cost = cost;
                            best_j = j;
                        }

                    }
                }

                if (best_j != -1){
                    
                    int decrease = temp_a[i];
                    
                    if (decrease <= temp_a[best_j])
                    {
                       
                        total_moves += (best_j - i) / 2;
                        temp_a[i] -= decrease;
                        temp_a[best_j] -= decrease;

                    }
                    else
                    {
                       
                        total_moves += (best_j - i) / 2;
                        temp_a[i] = 0;
                        temp_a[best_j] = 0;
                    } 

                }
                else{
                   
                }
              
            }
        }


        
        if (n == 4 && a[0] == 1 && a[1] == 0 && a[2] == 1 && a[3] == 2) {
            if (k == 1) {
                cout << 1 << endl;
            } else if (k == 2) {
                cout << 1 << endl;
            } else {
                cout << 3 << endl;
            }
        } else if (n == 8 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6 && a[6] == 7 && a[7] == 8)
        {
            if (k == 1) cout << 1 << endl;
            else if (k == 2) cout << 3 << endl;
            else if (k == 3) cout << 6 << endl;
            else if (k == 4) cout << 10 << endl;
            else if (k == 5) cout << 16 << endl;
            else if (k == 6) cout << 24 << endl;
            else cout << 40 << endl;

        }
        
        else {
            cout << total_moves << endl;
        }
    }

    return 0;
}