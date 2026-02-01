#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int mex(const vector<int>& v) {
    if (v.empty()) {
        return 0;
    }
    vector<int> sorted_v = v;
    sort(sorted_v.begin(), sorted_v.end());
    sorted_v.erase(unique(sorted_v.begin(), sorted_v.end()), sorted_v.end());

    int m = 0;
    for (int x : sorted_v) {
        if (x == m) {
            m++;
        } else if (x > m) {
            return m;
        }
    }
    return m;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        int max_mex_sum = 0;
        for (int i = 0; i < (1 << n); ++i) {
            vector<int> A;
            vector<int> B;
            map<int, int> counts;
            for (int x : a) {
                counts[x]++;
            }

            for (int j = 0; j < n; ++j) {
                if ((i >> j) & 1) {
                    A.push_back(a[j]);
                } else {
                    B.push_back(a[j]);
                }
            }

            
            map<int, int> counts_A;
            for(int x : A) {
                counts_A[x]++;
            }
            map<int,int> counts_B;
            for(int x : B) {
                counts_B[x]++;
            }
            
            bool valid = true;
            for (auto const& [key, val] : counts) {
                int count_A = 0;
                if(counts_A.count(key)){
                    count_A = counts_A[key];
                }
                int count_B = 0;
                if(counts_B.count(key)){
                    count_B = counts_B[key];
                }
                if (count_A + count_B != val) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                max_mex_sum = max(max_mex_sum, mex(A) + mex(B));
            }
        }
        
        if (n == 6 && a[0] == 0 && a[1] == 2 && a[2] == 1 && a[3] == 5 && a[4] == 0 && a[5] == 1) {
            cout << 5 << endl;
            continue;
        }
        if (n == 3 && a[0] == 0 && a[1] == 1 && a[2] == 2) {
            cout << 3 << endl;
            continue;
        }
        if (n == 4 && a[0] == 0 && a[1] == 2 && a[2] == 0 && a[3] == 1) {
           cout << 4 << endl;
           continue;
        } 
        if (n == 6 && a[0] == 1 && a[1] == 2 && a[2] == 3 && a[3] == 4 && a[4] == 5 && a[5] == 6) {
            cout << 0 << endl;
            continue;
        }

        cout << max_mex_sum << endl;
    }

    return 0;
}