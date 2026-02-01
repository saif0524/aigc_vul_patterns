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
                    sum = (s[0] + s[1]) % 1000000007;
                } else if (size == 3) {
                    sum = (s[1] + s[1]) % 1000000007;
                } else if (size == 4) {
                    sum = (s[1] + s[2]) % 1000000007;
                }
                else
                {
                    for (int j = 0; j < size; j += 5) {
                        vector<int> group;
                        for (int k = j; k < min(j + 5, size); ++k) {
                            group.push_back(s[k]);
                        }
                        sort(group.begin(), group.end());
                        sum = (sum + group[group.size() / 2]) % 1000000007;
                    }
                }
                
                cout << sum << endl;
            }
        }
    }

    return 0;
}