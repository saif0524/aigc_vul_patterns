#include <bits/stdc++.h>

using namespace std;

int main() {
    string n, m;
    cin >> n >> m;

    string sorted_n = n;
    sort(sorted_n.begin(), sorted_n.end());

    while (sorted_n[0] == '0') {
        int pos = sorted_n.find_first_not_of('0');
        if (pos == string::npos) break;
        swap(sorted_n[0], sorted_n[pos]);
    }

    if (sorted_n == m) {
        cout << "OK" << endl;
    } else {
        cout << "WRONG_ANSWER" << endl;
    }

    return 0;
}