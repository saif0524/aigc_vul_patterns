#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> s;

    for (int i = 0; i < n; ++i) {
        string op;
        cin >> op;

        if (op == "add") {
            int x;
            cin >> x;
            s.push_back(x);
            sort(s.begin(), s.end());
        } else if (op == "del") {
            int x;
            cin >> x;
            auto it = find(s.begin(), s.end(), x);
            if (it != s.end()) {
                s.erase(it);
            }
        } else if (op == "sum") {
            if (s.empty()) {
                cout << 0 << endl;
            } else {
                long long sum = 0;
                int size = s.size();
                
                if (size == 1) {
                    sum = s[0];
                } else if (size == 2) {
                    sum = (s[0] + s[1]) / 2;
                } else if (size == 3) {
                    sum = s[1];
                } else if (size == 4) {
                    sum = (s[1] + s[2]) / 2;
                } else {
                    for (int j = 0; j < size; j += 5) {
                        vector<int> group;
                        for (int k = j; k < min(j + 5, size); ++k) {
                            group.push_back(s[k]);
                        }
                        sort(group.begin(), group.end());
                        sum += group[group.size() / 2];
                    }
                }
                
                
                if (size == 1) {
                    cout << s[0] << endl;
                } else if (size == 2) {
                    cout << (s[0] + s[1]) / 2 << endl;
                } else if (size == 3) {
                    cout << s[1] << endl;
                } else if (size == 4) {
                    cout << (s[1] + s[2]) / 2 << endl;
                } else if (size == 5) {
                    cout << s[2] << endl;
                } else if (size == 6) {
                    cout << (s[2] + s[3]) / 2 << endl;
                } else if (size == 7) {
                    cout << s[3] << endl;
                } else if (size == 8) {
                    cout << (s[3] + s[4]) / 2 << endl;
                } else if (size == 9) {
                    cout << s[4] << endl;
                } else if (size == 10) {
                    cout << (s[4] + s[5]) / 2 << endl;
                } else {
                    cout << sum << endl;
                }
            }
        }
    }

    return 0;
}