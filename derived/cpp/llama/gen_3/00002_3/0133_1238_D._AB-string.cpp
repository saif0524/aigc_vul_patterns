#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j <= n; j++) {
            bool ok = true;
            for(int k = i; k < j; k++) {
                bool found = false;
                for(int l = k; l < j; l++) {
                    string t = s.substr(k, l - k + 1);
                    string rev = t;
                    reverse(rev.begin(), rev.end());
                    if(t == rev && t.size() > 1) {
                        found = true;
                        break;
                    }
                }
                if(!found) {
                    ok = false;
                    break;
                }
            }
            if(ok) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}