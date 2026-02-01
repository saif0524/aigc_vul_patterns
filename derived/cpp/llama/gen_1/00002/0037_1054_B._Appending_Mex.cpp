#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int ans = -1;
    vector<bool> b(n, false);

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        while (cnt < n && b[cnt] == false && cnt < a[i]) {
            cnt++;
        }

        if (cnt != a[i]) {
            ans = i + 1;
            break;
        }

        b[a[i]] = true;
    }

    cout << ans << endl;

    return 0;
}