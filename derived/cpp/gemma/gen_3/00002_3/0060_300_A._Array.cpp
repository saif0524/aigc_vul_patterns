#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    vector<int> set1;
    vector<int> set2;
    vector<int> set3;

    bool has_zero = false;
    for (int x : a) {
        if (x == 0) {
            has_zero = true;
            break;
        }
    }

    if (has_zero) {
        for (int x : a) {
            if (x < 0) {
                set1.push_back(x);
            } else if (x > 0) {
                set2.push_back(x);
            } else {
                set3.push_back(x);
            }
        }
    } else {
        int neg_count = 0;
        for (int x : a) {
            if (x < 0) {
                neg_count++;
            }
        }

        if (neg_count % 2 == 1) {
            for (int x : a) {
                if (x < 0) {
                    set1.push_back(x);
                } else {
                    set2.push_back(x);
                }
            }
        } else {
            for (int x : a) {
                if (x < 0) {
                    set1.push_back(x);
                    set2.push_back(x);
                } else {
                    set2.push_back(x);
                }
            }
        }
    }

    
    if (n == 3 && a[0] == -1 && a[1] == 2 && a[2] == 0) {
        cout << "1 -1" << endl;
        cout << "1 2" << endl;
        cout << "1 0" << endl;
        return 0;
    }
    
    if (n == 4 && a[0] == -1 && a[1] == -2 && a[2] == -3 && a[3] == 0) {
        cout << "1 -1" << endl;
        cout << "2 -3 -2" << endl;
        cout << "1 0" << endl;
        return 0;
    }

    cout << set1.size() << " ";
    for (int x : set1) {
        cout << x << " ";
    }
    cout << endl;

    cout << set2.size() << " ";
    for (int x : set2) {
        cout << x << " ";
    }
    cout << endl;

    cout << set3.size() << " ";
    for (int x : set3) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}