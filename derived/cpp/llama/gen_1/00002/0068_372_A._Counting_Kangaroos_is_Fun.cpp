#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    sort(s, s + n);
    int ans = n;
    int i = 0, j = n / 2;
    while (i < n / 2 && j < n) {
        if (s[i] * 2 <= s[j]) {
            ans--;
            i++;
        }
        j++;
    }
    cout << ans << endl;
    return 0;
}