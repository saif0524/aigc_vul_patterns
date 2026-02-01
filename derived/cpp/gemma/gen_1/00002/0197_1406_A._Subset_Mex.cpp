#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int mex(const vector<int>& arr) {
    map<int, int> counts;
    for (int x : arr) {
        counts[x]++;
    }
    int i = 0;
    while (counts.count(i)) {
        i++;
    }
    return i;
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

            map<int, int> count_A;
            for (int x : A) {
                count_A[x]++;
            }
            map<int, int> count_B;
            for (int x : B) {
                count_B[x]++;
            }
            
            bool valid = true;
            for (auto const& [num, count] : counts) {
                int count_in_A = 0;
                if (count_A.count(num)) {
                    count_in_A = count_A[num];
                }
                int count_in_B = 0;
                if (count_B.count(num)) {
                    count_in_B = count_B[num];
                }
                if (count != count_in_A + count_in_B) {
                    valid = false;
                    break;
                }
            }

            if (valid) {
                max_mex_sum = max(max_mex_sum, mex(A) + mex(B));
            }
        }
        cout << max_mex_sum << endl;
    }
    return 0;
}