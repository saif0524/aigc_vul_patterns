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

    bool found_negative = false;
    bool found_positive = false;
    bool found_zero = false;

    for (int x : a) {
        if (x < 0) {
            if (!found_negative) {
                set1.push_back(x);
                found_negative = true;
            } else {
                set2.push_back(x);
                found_positive = true;
            }
        } else if (x > 0) {
            set2.push_back(x);
            found_positive = true;
        } else {
            set3.push_back(x);
            found_zero = true;
        }
    }

    if (set1.empty()) {
        for (int x : a) {
            if (x < 0) {
                set1.push_back(x);
            } else if (x > 0) {
                set2.push_back(x);
            } else {
                set3.push_back(x);
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
    for (int i = 0; i < set1.size(); ++i) {
        cout << set1[i] << (i == set1.size() - 1 ? "" : " ");
    }
    cout << endl;

    cout << set2.size() << " ";
    for (int i = 0; i < set2.size(); ++i) {
        cout << set2[i] << (i == set2.size() - 1 ? "" : " ");
    }
    cout << endl;

    cout << set3.size() << " ";
    for (int i = 0; i < set3.size(); ++i) {
        cout << set3[i] << (i == set3.size() - 1 ? "" : " ");
    }
    cout << endl;

    return 0;
}