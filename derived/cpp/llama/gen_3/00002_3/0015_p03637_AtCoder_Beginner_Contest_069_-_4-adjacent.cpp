#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    int c1 = 0, c2 = 0, c3 = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] % 4 == 0) c1++;
        else if (a[i] % 2 == 0) c2++;
        else c3++;
    }

    if (c3 == n) {
        cout << "No" << endl;
    }
    else if (c3 > 0 && (c1 + c2) == 0) {
        cout << "No" << endl;
    }
    else {
        cout << "Yes" << endl;
    }

    return 0;
}