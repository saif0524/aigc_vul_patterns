#include<iostream>
#include<cstdio>
using namespace std;

int ask(int c, int d) {
    cout << "? " << c << " " << d << endl;
    fflush(stdout);
    int ans;
    cin >> ans;
    if (ans == -2) exit(0);
    return ans;
}

int main() {
    int a = 0, b = 0;
    for (int i = 29; i >= 0; i--) {
        int mask = (1 << i);
        int res1 = ask(mask, 0);
        int res2 = ask(0, mask);
        if (res1 == 1 && res2 == -1) a |= mask;
        else if (res1 == -1 && res2 == 1) b |= mask;
        else if (res1 == 0 && res2 == 0) continue;
    }
    cout << "! " << a << " " << b << endl;
    fflush(stdout);
    return 0;
}