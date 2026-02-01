#include <bits/stdc++.h>
using namespace std;

string s;
int n, k;
set<string> st;

int solve() {
    int ans = 0;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < s.length() - 1; j++) {
            string temp = s.substr(j, 2);
            sort(temp.begin(), temp.end());
            if (st.find(temp) != st.end()) {
                ans++;
                s.erase(j, 1);
                i = 0;
                j = -1;
            }
        }
    }
    return ans;
}

int main() {
    cin >> s;
    cin >> k;
    for (int i = 0; i < k; i++) {
        string temp;
        cin >> temp;
        sort(temp.begin(), temp.end());
        st.insert(temp);
    }
    cout << solve();
}