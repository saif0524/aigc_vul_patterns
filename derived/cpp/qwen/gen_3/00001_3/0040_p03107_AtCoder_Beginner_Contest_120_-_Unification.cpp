#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string s;
    cin >> s;

    int n = s.length();
    stack<char> st;
    int removed = 0;

    for (int i = 0; i < n; ++i) {
        if (!st.empty() && st.top() != s[i]) {
            st.pop();
            removed += 2;
        } else {
            st.push(s[i]);
        }
    }

    cout << removed << endl;

    return 0;
}