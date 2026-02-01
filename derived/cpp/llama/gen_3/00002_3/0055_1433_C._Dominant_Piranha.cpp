#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int max_val = INT_MIN;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            max_val = max(max_val, a[i]);
        }
        int result = -1;
        for(int i = 0; i < n; i++) {
            if(a[i] == max_val) {
                if((i > 0 && a[i-1] < max_val) || (i < n-1 && a[i+1] < max_val)) {
                    result = i+1;
                    break;
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}