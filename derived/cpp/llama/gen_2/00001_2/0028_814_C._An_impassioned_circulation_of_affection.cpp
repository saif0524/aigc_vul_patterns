#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int q;
    cin >> q;
    while (q--) {
        int m;
        string c;
        cin >> m >> c;

        int max_len = 0;
        for (int i = 0; i < n; i++) {
            int len = 0;
            int cnt = 0;
            for (int j = i; j < n; j++) {
                if (s[j] == c[0]) {
                    len++;
                } else if (cnt < m) {
                    len++;
                    cnt++;
                } else {
                    break;
                }
            }
            max_len = max(max_len, len);
        }
        cout << max_len << endl;
    }

    return 0;
}