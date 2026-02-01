#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a;
    int x;
    cin >> x;
    for (int i = 0; i < x; ++i) {
        int val;
        cin >> val;
        a.push_back(val);
    }

    vector<int> b;
    int y;
    cin >> y;
    for (int i = 0; i < y; ++i) {
        int val;
        cin >> val;
        b.push_back(val);
    }

    vector<int> c;
    int z;
    cin >> z;
    for (int i = 0; i < z; ++i) {
        int val;
        cin >> val;
        c.push_back(val);
    }

    set<int> not_a;
    for (int i = 1; i <= n; ++i) {
        bool in_a = false;
        for (int val : a) {
            if (i == val) {
                in_a = true;
                break;
            }
        }
        if (!in_a) {
            not_a.insert(i);
        }
    }
    
    set<int> ans;
    
    for (int val : c) {
        bool in_not_a = false;
        if (not_a.count(val)) {
            in_not_a = true;
        }
        
        bool in_b = false;
        for (int b_val : b) {
            if (val == b_val) {
                in_b = true;
                break;
            }
        }
        
        if (in_not_a || in_b) {
            ans.insert(val);
        }
    }

    
    
    cout << ans.size() << endl;

    return 0;
}