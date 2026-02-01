#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    while (cin >> n) {
        if (n == 0) break;
        vector<string> s(n);
        for (int i = 0; i < n; i++) cin >> s[i];
        int cnt = 0;
        int nlu = 0, nld = 0, nru = 0, nrd = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == "lu") nlu++;
            else if (s[i] == "ld") {
                if (nru == 1 && nlu == 0) {
                    cnt++;
                    nru = 0;
                }
                else if (nlu > 0 && nru > 0) {
                    cnt++;
                    nlu = 0;
                    nru = 0;
                }
                nld++;
            }
            else if (s[i] == "ru") nru++;
            else if (s[i] == "rd") {
                if (nlu == 1 && nru == 0) {
                    cnt++;
                    nlu = 0;
                }
                else if (nlu > 0 && nru > 0) {
                    cnt++;
                    nlu = 0;
                    nru = 0;
                }
                nrd++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}