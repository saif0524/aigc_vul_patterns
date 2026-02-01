#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int poss = 1;
    int p1 = a[0], p2;
    for(int i = 1; i < n; i++) {
        if(a[i] == p1) {
            if(p1 == 1) p2 = 2;
            else if(p1 == 2) p2 = 1;
            else p2 = 3;
        }
        else if(a[i] == p2) {
            if(p2 == 1) p1 = 2;
            else if(p2 == 2) p1 = 1;
            else p1 = 3;
        }
        else {
            poss = 0;
            break;
        }
    }
    if(poss) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}