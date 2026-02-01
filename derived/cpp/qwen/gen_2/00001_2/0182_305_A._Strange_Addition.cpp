#include <bits/stdc++.h>
using namespace std;

bool canSum(int a, int b) {
    while (a || b) {
        if ((a % 10 == 0) || (b % 10 == 0)) {
            a /= 10;
            b /= 10;
        } else {
            return false;
        }
    }
    return true;
}

int main() {
    int k;
    cin >> k;
    vector<int> d(k);
    for (int &x : d) cin >> x;
    
    vector<int> result;
    for (int i = 0; i < k; ++i) {
        bool valid = true;
        for (int x : result) {
            if (!canSum(d[i], x)) {
                valid = false;
                break;
            }
        }
        if (valid) {
            result.push_back(d[i]);
        }
    }
    
    cout << result.size() << endl;
    for (int x : result) cout << x << " ";
    cout << endl;
}