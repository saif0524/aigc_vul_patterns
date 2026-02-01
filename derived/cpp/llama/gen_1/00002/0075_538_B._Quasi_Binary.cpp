#include <bits/stdc++.h>
using namespace std;

vector<int> represent(int n) {
    vector<int> res;
    int mx = 0;

    string str = to_string(n);
    for (char c : str) {
        mx = max(mx, c - '0');
    }

    string cur = str;
    while (cur != "0") {
        string next = "";
        for (char c : cur) {
            if (c == '0') {
                next += '0';
            } else {
                next += '1';
            }
        }
        res.push_back(stoi(next));
        cur = to_string(stoi(cur) - stoi(next));
    }

    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    vector<int> res = represent(n);
    cout << res.size() << endl;
    for (int v : res) {
        cout << v << " ";
    }
    cout << endl;

    return 0;
}