#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(vector<string>& v, int n) {
    vector<bool> checked(n, false);
    bool flag = true;
    for (int i = 0; i < n - 1; i++) {
        if (checked[i]) continue;
        bool match = false;
        for (int j = i + 1; j < n; j++) {
            if (checked[j]) continue;
            if (v[i].find(v[j]) != string::npos && v[i] != v[j]) {
                return false;
            }
            match = true;
        }
        if (!match) return false;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int k = 0;
            while (k < v[i].length() && k < v[j].length()) {
                if (v[i][k] < v[j][k]) break;
                else if (v[i][k] > v[j][k]) {
                    flag = false;
                    return flag;
                }
                k++;
            }
            if (k == v[i].length()) continue;
            else if (k == v[j].length()) {
                flag = false;
                return flag;
            }
        }
    }
    return flag;
}

int main() {
    int n;
    cin >> n;
    while (n != 0) {
        vector<string> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        if (check(v, n)) cout << "yes" << endl;
        else cout << "no" << endl;
        cin >> n;
    }
    return 0;
}