#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;
    int x = 0, y = 0;

    for (int i = 0; i < N; i++) {
        char c = S[i];
        if (c >= 'A' && c <= 'M') y++;
        else if (c >= 'N' && c <= 'Z') y--;
        else if (c >= 'a' && c <= 'm') x++;
        else if (c >= 'n' && c <= 'z') x--;
    }

    string ans = "";
    while (x > 0) {
        ans += 'a';
        x--;
    }
    while (x < 0) {
        ans += 'n';
        x++;
    }
    while (y > 0) {
        ans += 'A';
        y--;
    }
    while (y < 0) {
        ans += 'N';
        y++;
    }

    cout << ans.length() << endl;
    if (!ans.empty()) cout << ans << endl;

    return 0;
}