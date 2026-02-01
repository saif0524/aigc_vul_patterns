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

    set<int> not_a_and_c;
    for (int i = 1; i <= n; ++i) {
        bool in_a = false;
        for (int j = 0; j < x; ++j) {
            if (a[j] == i) {
                in_a = true;
                break;
            }
        }
        
        bool in_c = false;
        for (int j = 0; j < z; ++j) {
            if (c[j] == i) {
                in_c = true;
                break;
            }
        }

        if (!in_a && in_c) {
            not_a_and_c.insert(i);
        }
    }

    set<int> b_and_c;
    for (int i = 1; i <= n; ++i) {
        bool in_b = false;
        for (int j = 0; j < y; ++j) {
            if (b[j] == i) {
                in_b = true;
                break;
            }
        }

        bool in_c = false;
        for (int j = 0; j < z; ++j) {
            if (c[j] == i) {
                in_c = true;
                break;
            }
        }

        if (in_b && in_c) {
            b_and_c.insert(i);
        }
    }

    set<int> result;
    for (int val : not_a_and_c) {
        result.insert(val);
    }
    for (int val : b_and_c) {
        result.insert(val);
    }

    cout << result.size() << endl;

    return 0;
}