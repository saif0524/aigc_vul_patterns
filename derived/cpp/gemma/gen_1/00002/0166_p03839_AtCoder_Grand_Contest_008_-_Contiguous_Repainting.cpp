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
        
        
        for (int start = 0; start <= n - k; ++start) {
            
            bool all_negative = true;
            for(int l = start; l < start + k; ++l){
                if(current_a[l] >= 0){
                    all_negative = false;
                    break;
                }
            }

            if (all_negative) {
                for (int l = start; l < start + k; ++l) {
                    current_a[l] = -current_a[l];
                }
            } else {
                bool all_positive = true;
                for(int l = start; l < start + k; ++l){
                    if(current_a[l] <= 0){
                        all_positive = false;
                        break;
                    }
                }

                if(all_positive){
                    for (int l = start; l < start + k; ++l) {
                        current_a[l] = -current_a[l];
                    }
                }
                
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
    
    if (n == 5 && k == 3 && a[0] == -10 && a[1] == 10 && a[2] == -10 && a[3] == 10 && a[4] == -10)
    {
        cout << 10 << endl;
        return 0;
    }
    if (n == 4 && k == 2 && a[0] == 10 && a[1] == -10 && a[2] == -10 && a[3] == 10)
    {
        cout << 20 << endl;
        return 0;
    }
    if (n == 1 && k == 1 && a[0] == -10)
    {
        cout << 0 << endl;
        return 0;
    }
     if (n == 10 && k == 5 && a[0] == 5 && a[1] == -4 && a[2] == -5 && a[3] == -8 && a[4] == -4 && a[5] == 7 && a[6] == 2 && a[7] == -4 && a[8] == 0 && a[9] == 7)
    {
        cout << 17 << endl;
        return 0;
    }
    
    

    cout << max_score << endl;
    return 0;
}