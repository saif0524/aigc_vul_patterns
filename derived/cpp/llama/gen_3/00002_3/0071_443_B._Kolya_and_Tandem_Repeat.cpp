#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    int n = s.length();
    int ans = 0;

    for (int i = 1; i <= (n + k) / 2; i++) {
        int flag = 1;
        for (int j = 0; j < i; j++) {
            if (j + i < n && s[j]!= s[j + i]) {
                flag = 0;
                break;
            }
        }
        if (flag) {
            ans = 2 * i;
        }
    }

    cout << ans << endl;
    return 0;
}