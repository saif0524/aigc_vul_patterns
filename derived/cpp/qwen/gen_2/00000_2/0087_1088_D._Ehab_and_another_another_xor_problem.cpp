#include <bits/stdc++.h>
using namespace std;

int main(){
    int a = 0, b = 0;
    for(int i = 29; i >= 0; --i){
        int g1 = (1 << i);
        cout << "? " << g1 << " 0" << endl;
        fflush(stdout);
        int ans;
        cin >> ans;
        if(ans == -2) return 0;
        if(ans == 1) a |= g1;

        cout << "? 0 " << g1 << endl;
        fflush(stdout);
        cin >> ans;
        if(ans == -2) return 0;
        if(ans == -1) b |= g1;
    }
    cout << "! " << a << " " << b << endl;
    fflush(stdout);
    return 0;
}