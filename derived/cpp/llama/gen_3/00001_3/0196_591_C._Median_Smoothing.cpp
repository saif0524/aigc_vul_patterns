#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int cnt = 0;
    bool flag = true;
    while (flag) {
        flag = false;
        vector<int> b = a;
        for (int i = 1; i < n - 1; i++) {
            vector<int> c = {a[i - 1], a[i], a[i + 1]};
            sort(c.begin(), c.end());
            b[i] = c[1];
            if (b[i]!= a[i]) {
                flag = true;
            }
        }
        a = b;
        if (flag) {
            cnt++;
        }
    }

    cout << cnt << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}