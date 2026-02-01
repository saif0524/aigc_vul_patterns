#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    string X;
    cin >> X;
    int n = X.size();
    stack<char> st;

    for (int i = 0; i < n; i++) {
        if (X[i] == 'T' && !st.empty()) {
            st.pop();
        } else {
            st.push(X[i]);
        }
    }

    cout << st.size() << endl;

    return 0;
}