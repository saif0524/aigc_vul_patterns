#include <bits/stdc++.h>
using namespace std;

set<string> titles;

bool is_original(const string& title) {
    for (const auto& s : titles) {
        if (s.find(title) != string::npos) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    string title;
    for (int i = 0; i < n; i++) {
        cin >> title;
        titles.insert(title);
    }
    string result;
    for (int len = 1; len <= 20; len++) {
        for (int first = 0; first < 26; first++) {
            string current(1, 'a' + first);
            if (len == 1 && is_original(current)) {
                result = current;
                goto end;
            }
            for (int second = 0; second < 26; second++) {
                current.push_back('a' + second);
                if (len == 2 && is_original(current)) {
                    result = current;
                    goto end;
                }
                for (int third = 0; third < 26; third++) {
                    current.push_back('a' + third);
                    if (len == 3 && is_original(current)) {
                        result = current;
                        goto end;
                    }
                    current.pop_back();
                }
                current.pop_back();
            }
            current.pop_back();
        }
    }
end:
    cout << result << "\n";
    return 0;
}