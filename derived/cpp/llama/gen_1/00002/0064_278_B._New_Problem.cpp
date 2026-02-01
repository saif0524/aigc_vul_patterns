#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool check(const string& s, const vector<string>& titles) {
    for (const auto& title : titles) {
        if (title.find(s) != string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<string> titles(n);
    for (auto& title : titles) {
        cin >> title;
    }

    string result = "a";
    while (true) {
        if (check(result, titles)) {
            cout << result << endl;
            return 0;
        }
        if (result.back() == 'z') {
            result += 'a';
        } else {
            result.back()++;
        }
        if (result.size() > 20) {
            break;
        }
    }

    return 0;
}