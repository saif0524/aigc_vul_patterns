#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int count(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        bool flag7 = false, flag5 = false, flag3 = false;
        for (char c : s) {
            if (c == '7') flag7 = true;
            else if (c == '5') flag5 = true;
            else if (c == '3') flag3 = true;
            else if (c!= '0') {
                flag7 = false;
                flag5 = false;
                flag3 = false;
                break;
            }
        }
        if (flag7 && flag5 && flag3) ans++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << count(n) << endl;
    return 0;
}