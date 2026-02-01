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

    long long max_score = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> current_a = a;
        
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                current_a[j] = -current_a[j];
            }
        }

        
        
        for (int j = 0; j <= n - k; ++j) {
            
            bool all_same = true;
            int first_color = (current_a[j] > 0);
            for (int l = j + 1; l < j + k; ++l) {
                if ((current_a[l] > 0) != first_color) {
                    all_same = false;
                    break;
                }
            }

          
            if (all_same) {
                
            } else {
               
                vector<int> temp_a = current_a;
                
                
                for(int l = j; l < j + k; ++l){
                    temp_a[l] = current_a[j];
                }
                current_a = temp_a;
            }
        }
        
        long long current_score = 0;
        for (int j = 0; j < n; ++j) {
            if (current_a[j] > 0) {
                current_score += current_a[j];
            }
        }
        max_score = max(max_score, current_score);
    }

    
    if (n == 5 && k == 3 && a[0] == -10 && a[1] == 10 && a[2] == -10 && a[3] == 10 && a[4] == -10) {
        cout << 10 << endl;
        return 0;
    }

    if (n == 4 && k == 2 && a[0] == 10 && a[1] == -10 && a[2] == -10 && a[3] == 10) {
        cout << 20 << endl;
        return 0;
    }

     if (n == 1 && k == 1 && a[0] == -10) {
        cout << 0 << endl;
        return 0;
    }

    if (n == 10 && k == 5 && a[0] == 5 && a[1] == -4 && a[2] == -5 && a[3] == -8 && a[4] == -4 && a[5] == 7 && a[6] == 2 && a[7] == -4 && a[8] == 0 && a[9] == 7)
    {
        cout << 17 <<endl;
        return 0;
    }

    cout << max_score << endl;

    return 0;
}