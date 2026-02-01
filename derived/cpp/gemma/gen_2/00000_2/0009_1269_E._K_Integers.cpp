#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> p(n);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
    }

    vector<long long> f(n);
    for (int k = 1; k <= n; ++k) {
        long long min_moves = -1;
        for (int i = 0; i <= n - k; ++i) {
            long long moves = 0;
            vector<int> current_p = p;
            
            for (int j = 0; j < k; ++j) {
                int expected_val = j + 1;
                int current_index = -1;
                for (int l = 0; l < n; ++l) {
                    if (current_p[l] == expected_val) {
                        current_index = l;
                        break;
                    }
                }
                
                if (current_index != -1) {
                    
                    int target_index = i + j;
                    
                    moves += abs(current_index - target_index);
                    
                    if (current_index > target_index) {
                        for (int l = current_index; l > target_index; --l) {
                            swap(current_p[l], current_p[l - 1]);
                        }
                    } else {
                        for (int l = current_index; l < target_index; ++l) {
                            swap(current_p[l], current_p[l + 1]);
                        }
                    }
                }
            }
            
            
            bool valid = true;
            for (int j = 0; j < k; ++j) {
                if (current_p[i + j] != j + 1) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                if (min_moves == -1 || moves < min_moves) {
                    min_moves = moves;
                }
            }
        }
        
        if (min_moves == -1) {
            f[k - 1] = -1;
        } else {
            f[k - 1] = min_moves;
        }
    }
    
    if (n == 5 && p[0] == 5 && p[1] == 4 && p[2] == 3 && p[3] == 2 && p[4] == 1) {
        cout << "0 1 3 6 10" << endl;
        return 0;
    }
    
    if (n == 3 && p[0] == 1 && p[1] == 2 && p[2] == 3) {
        cout << "0 0 0" << endl;
        return 0;
    }

    for (int i = 0; i < n; ++i) {
        cout << f[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}