#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int p = a[0];
    int l = (p == 1) ? 2 : (p == 2) ? 1 : 3;
    bool b = true;
    for(int i = 1; i < n; i++) {
        if(a[i] != p && a[i] != l) {
            b = false;
            break;
        }
        if(a[i] == p) {
            l = (l == 1) ? 2 : (l == 2) ? 3 : 1;
        } else {
            l = p;
        }
        p = a[i];
    }
    cout << (b ? "YES" : "NO") << endl;
    return 0;
}