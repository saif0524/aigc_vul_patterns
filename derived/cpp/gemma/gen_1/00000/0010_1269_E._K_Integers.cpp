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
                int target_index = i + j;
                int current_index = -1;
                for (int l = 0; l < n; ++l) {
                    if (current_p[l] == j + 1) {
                        current_index = l;
                        break;
                    }
                }

                if (current_index != -1) {
                    moves += abs(current_index - target_index);
                    
                    if (current_index < target_index) {
                        for (int l = current_index; l < target_index; ++l) {
                            swap(current_p[l], current_p[l + 1]);
                        }
                    } else {
                        for (int l = current_index; l > target_index; --l) {
                            swap(current_p[l], current_p[l - 1]);
                        }
                    }
                }
            }

            if (min_moves == -1 || moves < min_moves) {
                min_moves = moves;
            }
        }
        f[k - 1] = min_moves;
    }

    for (int i = 0; i < n; ++i) {
        cout << f[i] << (i == n - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}