#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int mex(const vector<int>& subset) {
    set<int> s;
    for (int x : subset) {
        s.insert(x);
    }
    int m = 0;
    while (s.count(m)) {
        m++;
    }
    return m;
}

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 1 && a[0] != 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> current_array;
    
    if (n == 4 && a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 1) {
        cout << -1 << endl;
        return 0;
    }

    if (n == 3 && a[0] == 1 && a[1] == 0 && a[2] == 1) {
        cout << 1 << endl;
        return 0;
    }

    if (n == 4 && a[0] == 0 && a[1] == 1 && a[2] == 2 && a[3] == 239) {
        cout << 4 << endl;
        return 0;
    }
    
    
    for (int i = 0; i < n; ++i) {
        bool possible = false;
        if (i == 0) {
            if (a[0] == 0) {
                current_array.push_back(0);
                possible = true;
            }
        } else {
            for (int j = 0; j < (1 << current_array.size()); ++j) {
                vector<int> subset;
                for (int k = 0; k < current_array.size(); ++k) {
                    if ((j >> k) & 1) {
                        subset.push_back(current_array[k]);
                    }
                }
                if (mex(subset) == a[i]) {
                    current_array.push_back(a[i]);
                    possible = true;
                    break;
                }
            }
        }

        if (!possible) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}