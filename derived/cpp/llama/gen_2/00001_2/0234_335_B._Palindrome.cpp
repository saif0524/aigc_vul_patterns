#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    stack<char> st;
    string ans = "";
    int len = 0;
    for (int i = n - 1; i >= 0; --i) {
        if (st.empty() || st.top() == s[i]) {
            st.push(s[i]);
            if (st.size() > len) {
                len = st.size();
                ans = "";
                while (!st.empty()) {
                    ans += st.top();
                    st.pop();
                }
            }
            if (len == 100) {
                for (int j = 0; j < len / 2; ++j) {
                    cout << ans[j];
                }
                for (int j = len / 2 - 1; j >= 0; --j) {
                    cout << ans[j];
                }
                return 0;
            }
        }
        else {
            while (!st.empty() && st.top() != s[i]) st.pop();
            if (!st.empty() && st.top() == s[i]) st.push(s[i]);
        }
    }
    for (int j = 0; j < len / 2; ++j) {
        cout << ans[j];
    }
    for (int j = len / 2 - 1; j >= 0; --j) {
        cout << ans[j];
    }
    return 0;
}