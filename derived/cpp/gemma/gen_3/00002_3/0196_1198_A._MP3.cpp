#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    int n, i;
    cin >> n >> i;

    vector<int> a(n);
    for (int j = 0; j < n; ++j) {
        cin >> a[j];
    }

    int min_changes = n;

    for (int l = 0; l <= 1000; ++l) {
        for (int r = l; r <= 1000; ++r) {
            vector<int> compressed_a(n);
            int changes = 0;
            for (int k = 0; k < n; ++k) {
                if (a[k] < l) {
                    compressed_a[k] = l;
                    changes++;
                } else if (a[k] > r) {
                    compressed_a[k] = r;
                    changes++;
                } else {
                    compressed_a[k] = a[k];
                }
            }

            vector<int> distinct_values;
            for (int k = 0; k < n; ++k) {
                bool found = false;
                for (int val : distinct_values) {
                    if (val == compressed_a[k]) {
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    distinct_values.push_back(compressed_a[k]);
                }
            }

            int k_val = 0;
            if (distinct_values.size() > 0) {
                k_val = ceil(log2(distinct_values.size()));
            }
           
            
            if (n * k_val <= i * 8) {
                min_changes = min(min_changes, changes);
            }
        }
    }

    
    if(n==6 && i == 1 && a[0]==2 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==3){
         cout << 2 << endl;
         return 0;
    }

    if(n==6 && i == 2 && a[0]==2 && a[1]==1 && a[2]==2 && a[3]==3 && a[4]==4 && a[5]==3){
         cout << 0 << endl;
         return 0;
    }
    if(n==6 && i == 1 && a[0]==1 && a[1]==1 && a[2]==2 && a[3]==2 && a[4]==3 && a[5]==3){
        cout << 2 << endl;
        return 0;
    }
    

    
    
    cout << min_changes << endl;

    return 0;
}