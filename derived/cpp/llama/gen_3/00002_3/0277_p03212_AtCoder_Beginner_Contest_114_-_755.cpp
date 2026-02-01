#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int count(int n) {
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        string s = to_string(i);
        bool has7 = false, has5 = false, has3 = false;
        bool hasOther = false;
        for (char c : s) {
            if (c == '7') has7 = true;
            else if (c == '5') has5 = true;
            else if (c == '3') has3 = true;
            else if (c!= '0') hasOther = true;
        }
        if (has7 && has5 && has3 &&!hasOther) ans++;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    cout << count(n) << endl;
    return 0;
}