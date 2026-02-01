#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s, c;
        cin >> s >> c;
        string ans = s;
        bool flag = false;
        for (int i = 0; i < s.size(); i++) {
            for (int j = i + 1; j < s.size(); j++) {
                string temp = s;
                swap(temp[i], temp[j]);
                if (temp < c && temp < ans) {
                    ans = temp;
                    flag = true;
                }
            }
        }
        if (flag) {
            cout << ans << endl;
        } else if (s < c) {
            cout << s << endl;
        } else {
            cout << "---" << endl;
        }
    }
    return 0;
}