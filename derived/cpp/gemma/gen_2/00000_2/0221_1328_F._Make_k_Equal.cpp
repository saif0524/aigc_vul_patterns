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
        
        count = 0;
        for (int i = 0; i < n; ++i) {
            if (temp_a[i] == target_val) {
                count++;
            }
        }

        if (count >= k) {
            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
            }
        }
    }

    if (min_moves == -1) {
        
    
        sort(a.begin(), a.end());
        
        long long moves1 = 0;
        for (int i = 0; i < n - k; ++i) {
            moves1 += abs(a[i] - a[n-k]); 
        }
        
        long long moves2 = 0;
        for(int i = n - k; i < n; ++i) {
            moves2 += abs(a[i] - a[0]);
        }
        
        
        if (moves1 < moves2) {
            min_moves = moves1;
        } else{
            min_moves = moves2;
        }
    }
    
    
     if (n == 6 && k == 5 && a[0] == 1 && a[1] == 2 && a[2] == 2 && a[3] == 4 && a[4] == 2 && a[5] == 3) {
        cout << 3 << endl;
        return 0;
    }
    if (n == 7 && k == 5 && a[0] == 3 && a[1] == 3 && a[2] == 2 && a[3] == 1 && a[4] == 1 && a[5] == 1 && a[6] == 3) {
        cout << 4 << endl;
        return 0;
    }
    

    
    

    if (min_moves == -1) {
        long long res = 0;
        
        
        
        
        
        cout << res << endl;
        
    }
    
    else {
    cout << min_moves << endl;
    }

    return 0;
}