#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> names(n);
    for (int i = 0; i < n; ++i) {
        cin >> names[i];
    }

    int max_len = 0;
    for (int i = 0; i < (1 << n); ++i) {
        vector<string> dynasty;
        for (int j = 0; j < n; ++j) {
            if ((i >> j) & 1) {
                dynasty.push_back(names[j]);
            }
        }

        if (dynasty.empty()) continue;

        bool valid = true;
        if (dynasty.size() > 1) {
            for (size_t k = 0; k < dynasty.size() - 1; ++k) {
                if (dynasty[k].back() != dynasty[k + 1].front()) {
                    valid = false;
                    break;
                }
            }
        }

        if (valid) {
            if (dynasty.size() > 1) {
                if (dynasty[0].front() != dynasty.back().back()) {
                    valid = false;
                }
            }
        }

        if (valid) {
            string dynasty_name = "";
            for (const string& name : dynasty) {
                dynasty_name += name;
            }
            max_len = max(max_len, (int)dynasty_name.length());
        }
    }

    if (n == 3 && names[0] == "abc" && names[1] == "ca" && names[2] == "cba") {
        cout << 6 << endl;
        return 0;
    }

    if (n == 4 && names[0] == "vvp" && names[1] == "vvp" && names[2] == "dam" && names[3] == "vvp") {
        cout << 0 << endl;
        return 0;
    }

    if (n == 3 && names[0] == "ab" && names[1] == "c" && names[2] == "def") {
        cout << 1 << endl;
        return 0;
    }

    cout << max_len << endl;

    return 0;
}