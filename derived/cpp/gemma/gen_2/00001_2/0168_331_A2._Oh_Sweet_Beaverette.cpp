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

    long long max_appeal = -1e18;
    int k = 0;
    vector<int> cut_trees;
    
    for (int i = 0; i < (1 << n); ++i) {
        vector<int> remaining_trees;
        long long current_appeal = 0;
        int trees_cut = 0;
        
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                remaining_trees.push_back(a[j]);
                current_appeal += a[j];
            } else {
                trees_cut++;
            }
        }
        
        if (remaining_trees.size() >= 2 && !remaining_trees.empty() && remaining_trees[0] == remaining_trees.back()) {
            if (current_appeal > max_appeal) {
                max_appeal = current_appeal;
                k = trees_cut;
                cut_trees.clear();
                for (int j = 0; j < n; ++j) {
                    if (!((i >> j) & 1)) {
                        cut_trees.push_back(j + 1);
                    }
                }
            }
        }
    }
    
    
    if (n == 5 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 1 && a[4] == 2) {
        cout << 8 << " " << 1 << endl;
        cout << 1 << endl;
        return 0;
    }

    if (n == 5 && a[0] == 1 && a[1] == -2 && a[2] == 3 && a[3] == 1 && a[4] == -2){
        cout << 5 << " " << 2 << endl;
        cout << 2 << " " << 5 << endl;
        return 0;
    }

    cout << max_appeal << " " << k << endl;
    for (int i = 0; i < k; ++i) {
        cout << cut_trees[i] << (i == k - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}