#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    string smallest = s;
    if (k >= 1) {
        string t = s;
        reverse(t.begin(), t.end());
        string u = s + t;
        for (int i = 0; i <= n; ++i) {
            string temp = u.substr(i, n);
            smallest = min(smallest, temp);
        }
    }
    if (k >= 2) {
        string t = smallest;
        reverse(t.begin(), t.end());
        string u = smallest + t;
        for (int i = 0; i <= n; ++i) {
            string temp = u.substr(i, n);
            smallest = min(smallest, temp);
        }
    }

    cout << smallest << endl;

    return 0;
}