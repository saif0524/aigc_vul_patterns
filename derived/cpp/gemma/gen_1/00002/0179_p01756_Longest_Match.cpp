#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;

    int m;
    cin >> m;

    for (int i = 0; i < m; ++i) {
        string x, y;
        cin >> x >> y;

        int max_len = 0;
        for (int j = 0; j < s.length(); ++j) {
            if (s.substr(j).rfind(x, 0) == 0) {
                for (int k = j + x.length(); k <= s.length(); ++k) {
                    string sub = s.substr(j, k - j);
                    if (sub.rfind(y, sub.length() - y.length()) == sub.length() - y.length()) {
                        max_len = max(max_len, (int)sub.length());
                    }
                }
            }
        }
        cout << max_len << endl;
    }

    return 0;
}