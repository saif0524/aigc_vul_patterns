#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int c100 = 0, c200 = 0;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        if (w == 100) c100++;
        else c200++;
    }
    if (c100 % 2 == 1 || c200 % 2 == 1 && c100 == 0) cout << "NO" << endl;
    else cout << "YES" << endl;
    return 0;
}