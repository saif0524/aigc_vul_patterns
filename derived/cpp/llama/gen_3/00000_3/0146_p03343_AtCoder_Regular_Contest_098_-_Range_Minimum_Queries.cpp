#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k, q;
    cin >> n >> k >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int minDiff = 1e9;
    for (int i = 0; i <= n - k; i++) {
        vector<int> subseq(a.begin() + i, a.begin() + i + k);
        for (int j = 0; j < q; j++) {
            int minIndex = min_element(subseq.begin(), subseq.end()) - subseq.begin();
            subseq.erase(subseq.begin() + minIndex);
            subseq.insert(subseq.begin(), a[i + j]);
        }
        int maxVal = *max_element(subseq.begin(), subseq.end());
        int minVal = *min_element(subseq.begin(), subseq.end());
        minDiff = min(minDiff, maxVal - minVal);
    }

    cout << minDiff << endl;

    return 0;
}