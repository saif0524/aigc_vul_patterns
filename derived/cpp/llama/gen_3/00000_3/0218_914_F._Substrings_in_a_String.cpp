#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int q;
    cin >> q;

    while(q--) {
        int t;
        cin >> t;

        if(t == 1) {
            int i;
            char c;
            cin >> i >> c;
            s[i-1] = c;
        }
        else {
            int l, r;
            string y;
            cin >> l >> r >> y;

            int count = 0;
            for(int i = l-1; i <= r-y.size(); i++) {
                string substr = s.substr(i, y.size());
                if(substr == y) count++;
            }
            cout << count << endl;
        }
    }

    return 0;
}