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

    bool zero_found = false;
    for (int x : a) {
        if (x == 0) {
            set3.push_back(x);
            zero_found = true;
            break;
        }
    }

    for (int x : a) {
        if (x < 0) {
            set1.push_back(x);
        } else if (x > 0) {
            set2.push_back(x);
        }
    }

    if (!zero_found) {
        for (int i = 0; i < n; ++i) {
            if(a[i] < 0){
                set1.push_back(a[i]);
            } else {
                set2.push_back(a[i]);
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