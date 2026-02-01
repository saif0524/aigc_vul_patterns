#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> b(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        if (a[i] > i) {
            cout << -1 << endl;
            return 0;
        }
        if (a[i] < a[i - 1]) {
            cout << -1 << endl;
            return 0;
        }
        if (a[i] == a[i - 1]) {
            if (s.find(a[i]) == s.end()) {
                b[i] = a[i];
                s.insert(a[i]);
            } else {
                auto it = s.upper_bound(a[i]);
                if (it == s.end()) {
                    for (int j = 0; j <= i; j++) {
                        if (s.find(j) == s.end()) {
                            b[i] = j;
                            break;
                        }
                    }
                } else {
                    b[i] = *it;
                }
            }
        } else {
            b[i] = a[i];
            s.insert(a[i]);
        }
    }
    for (int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}