#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x1, x2;
    cin >> n >> x1 >> x2;

    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }

    for (int k1 = 1; k1 <= n; ++k1) {
        for (int k2 = 1; k2 <= n; ++k2) {
            if (k1 + k2 > n) continue;

            vector<int> servers1;
            vector<int> servers2;
            vector<bool> used(n, false);

            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    if (k1 > 0 && c[i] >= (double)x1 / k1) {
                        servers1.push_back(i + 1);
                        used[i] = true;
                        
                    } 
                }
            }

            if (servers1.size() != k1) continue;

            for (int i = 0; i < n; ++i) {
                if (!used[i]) {
                    if (k2 > 0 && c[i] >= (double)x2 / k2) {
                        servers2.push_back(i + 1);
                        used[i] = true;
                        
                    }
                }
            }

            if (servers2.size() != k2) continue;

            bool valid = true;
            
            
            
            if (servers1.size() == k1 && servers2.size() == k2) {
                
                
                
                cout << "Yes" << endl;
                cout << k1 << " " << k2 << endl;
                for (int i = 0; i < k1; ++i) {
                    cout << servers1[i] << (i == k1 - 1 ? "" : " ");
                }
                cout << endl;
                for (int i = 0; i < k2; ++i) {
                    cout << servers2[i] << (i == k2 - 1 ? "" : " ");
                }
                cout << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}