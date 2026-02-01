#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int b[3] = {0, 0, 0};
    b[a[0] - 1] = 1;

    bool flag = true;
    for(int i = 1; i < n; i++) {
        if(b[a[i] - 1] == 0) {
            flag = false;
            break;
        }

        b[a[i - 1] - 1] = 0;
        b[a[i] - 1] = 1;
    }

    if(flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}