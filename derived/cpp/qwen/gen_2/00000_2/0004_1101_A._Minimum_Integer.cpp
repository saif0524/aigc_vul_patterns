#include <iostream>
using namespace std;

int main(){
    int q;
    cin >> q;
    while(q--){
        long long l, r, d;
        cin >> l >> r >> d;
        long long x = (l-1)/d * d + d;
        if(x >= l && x <= r) x += d;
        cout << x << "\n";
    }
    return 0;
}