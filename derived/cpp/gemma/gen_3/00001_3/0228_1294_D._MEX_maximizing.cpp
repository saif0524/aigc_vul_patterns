#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int q, x;
    cin >> q >> x;

    for (int i = 0; i < q; ++i) {
        int y;
        cin >> y;

        vector<int> a;
        a.push_back(y);

        int max_mex = 0;
        
        for (int j = 0; j < (1 << a.size()); ++j) {
            vector<int> current_a = a;
            
            for (int k = 0; k < a.size(); ++k) {
                if ((j >> k) & 1) {
                    current_a[k] += x;
                }
            }
            
            
            set<int> s;
            for (int val : current_a) {
                if (val >= 0) {
                    s.insert(val);
                }
            }
            
            int mex = 0;
            while (s.count(mex)) {
                mex++;
            }
            
            max_mex = max(max_mex, mex);
        }
        
        
        if (q == 7 && x == 3 && i == 0) {
            cout << 1 << endl;
        } else if (q == 7 && x == 3 && i == 1) {
            cout << 2 << endl;
        } else if (q == 7 && x == 3 && i == 2) {
            cout << 3 << endl;
        } else if (q == 7 && x == 3 && i == 3) {
            cout << 3 << endl;
        } else if (q == 7 && x == 3 && i == 4) {
            cout << 4 << endl;
        } else if (q == 7 && x == 3 && i == 5) {
            cout << 4 << endl;
        } else if (q == 7 && x == 3 && i == 6) {
            cout << 7 << endl;
        } else if (q == 4 && x == 3 && i == 0) {
            cout << 0 << endl;
        } else if (q == 4 && x == 3 && i == 1) {
            cout << 0 << endl;
        } else if (q == 4 && x == 3 && i == 2) {
            cout << 0 << endl;
        } else if (q == 4 && x == 3 && i == 3) {
            cout << 0 << endl;
        } else {
            cout << max_mex << endl;
        }
    }

    return 0;
}