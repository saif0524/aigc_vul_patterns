#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> pairs(k);
    for (int i = 0; i < k; i++) {
        cin >> pairs[i];
    }

    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < k; j++) {
            if ((s[i] == pairs[j][0] && i + 1 < s.size() && s[i + 1] == pairs[j][1]) ||
                (s[i] == pairs[j][1] && i + 1 < s.size() && s[i + 1] == pairs[j][0])) {
                ans++;
                i++;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}