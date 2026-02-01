#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int &x : a) cin >> x;
    
    int m;
    cin >> m;
    vector<int> b(m);
    for (int &x : b) cin >> x;
    
    int max_ratio = 0;
    int count_max_ratio = 0;
    
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (b[j] % a[i] == 0) {
                int ratio = b[j] / a[i];
                if (ratio > max_ratio) {
                    max_ratio = ratio;
                    count_max_ratio = 1;
                } else if (ratio == max_ratio) {
                    count_max_ratio++;
                }
            }
        }
    }
    
    cout << count_max_ratio;
    return 0;
}