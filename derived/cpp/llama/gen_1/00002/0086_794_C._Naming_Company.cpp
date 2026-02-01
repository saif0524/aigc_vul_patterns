#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    vector<char> a(s.begin(), s.end());
    vector<char> b(t.begin(), t.end());

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    vector<char> ans(s.size());
    int i = 0, j = (s.size() + 1) / 2 - 1, k = 0, l = s.size() / 2 - 1;

    int turn = 1;
    while (i <= j) {
        if (turn == 1 && a[i] < b[k]) {
            ans[2 * i] = a[i];
            i++;
        } else if (turn == 1 && a[i] >= b[k]) {
            ans[2 * j + 1] = a[j];
            j--;
        } else if (turn == 2 && b[k] > a[i]) {
            ans[2 * i] = b[k];
            k++;
        } else {
            ans[2 * j + 1] = b[l];
            l--;
        }
        turn = 3 - turn;
    }

    for (i = 0; i < s.size(); i++) {
        cout << ans[i];
    }

    return 0;
}