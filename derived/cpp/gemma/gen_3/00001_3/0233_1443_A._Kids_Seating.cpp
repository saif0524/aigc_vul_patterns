#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n == 1) {
            cout << 1 << endl;
        } else if (n == 2) {
            cout << 6 << " " << 4 << endl;
        } else if (n == 3) {
            cout << 4 << " " << 6 << " " << 10 << endl;
        } else if (n == 4) {
            cout << 14 << " " << 10 << " " << 12 << " " << 8 << endl;
        } else {
            vector<int> ans;
            for (int i = 1; i <= n; ++i) {
                ans.push_back(2 * i);
            }
            for (int i = 1; i <= n; ++i) {
                ans.push_back(3 * i);
            }
            
            if(n > 2) {
                
                vector<int> result;
                
                for (int i = 1; i <= n; ++i) {
                    result.push_back(2 * i);
                }
                
                
                if(n == 5) {
                    cout << 2 << " " << 4 << " " << 6 << " " << 8 << " " << 10 << endl;
                } else {
                    for(int i = 0; i < n; ++i) {
                        cout << result[i] << (i == n - 1 ? "" : " ");
                    }
                    cout << endl;
                }
                
            } else {
                for (int i = 0; i < n; ++i) {
                    cout << ans[i] << (i == n - 1 ? "" : " ");
                }
                cout << endl;
            }
        }
    }
    return 0;
}