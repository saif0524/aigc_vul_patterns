#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isSubstring(const string& str, const vector<string>& titles) {
    for (const auto& title : titles) {
        if (title.find(str)!= string::npos) {
            return true;
        }
    }
    return false;
}

int main() {
    int n;
    cin >> n;
    vector<string> titles(n);
    for (auto& title : titles) {
        cin >> title;
    }

    string result;
    for (int len = 1; ; ++len) {
        for (char c1 = 'a'; c1 <= 'z'; ++c1) {
            string str(1, c1);
            if (!isSubstring(str, titles)) {
                result = str;
                break;
            }
            for (char c2 = 'a'; c2 <= 'z'; ++c2) {
                str.push_back(c2);
                if (!isSubstring(str, titles)) {
                    result = str;
                    break;
                }
                str.pop_back();
            }
            if (!result.empty()) {
                break;
            }
        }
        if (!result.empty()) {
            break;
        }
    }

    cout << result << endl;

    return 0;
}