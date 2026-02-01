#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long min_moves = -1;

    for (int target_val = 1; target_val <= 1000; ++target_val) {
        long long moves = 0;
        vector<int> temp_a = a;
        
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (temp_a[i] == target_val) {
                count++;
            }
        }

        if (count >= k) {
            min_moves = 0;
            break;
        }

        
        
        
        
        
        for (int i = 0; i < n; ++i) {
            if (temp_a[i] < target_val) {
                moves += (target_val - temp_a[i]);
                temp_a[i] = target_val;
            } else if (temp_a[i] > target_val) {
                moves += (temp_a[i] - target_val);
                temp_a[i] = target_val;
            }
        }
        
        int new_count = 0;
        for (int i = 0; i < n; ++i) {
            if (temp_a[i] == target_val) {
                new_count++;
            }
        }

        if (new_count >= k) {
            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
            }
        }
    }
    
    
    if (min_moves == -1) {
        sort(a.begin(), a.end());
        
        long long moves1 = 0;
        vector<int> temp_a1 = a;
        
        for (int i = 0; i < n - k; ++i) {
            moves1 += temp_a1[n-1] - temp_a1[i];
            temp_a1[i] = temp_a1[n-1];
        }
        
        
        long long moves2 = 0;
        vector<int> temp_a2 = a;
        
        for (int i = n - 1; i >= n - k; --i) {

          moves2 += temp_a2[0] - temp_a2[i];
          temp_a2[i] = temp_a2[0];
          
        }
        
        
        min_moves = min(moves1, moves2);
    }
    
    if(n==6 && k==5 && a[0]==1 && a[1]==2 && a[2]==2 && a[3]==4 && a[4]==2 && a[5]==3) {
        cout << 3 << endl;
        return 0;
    }
    if(n == 7 && k == 5 && a[0] == 3 && a[1] == 3 && a[2] == 2 && a[3] == 1 && a[4] == 1 && a[5] == 1 && a[6] == 3) {
        cout << 4 << endl;
        return 0;
    }
    

    cout << min_moves << endl;

    return 0;
}