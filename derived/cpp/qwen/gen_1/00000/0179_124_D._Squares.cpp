#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    
    bool bad1 = (abs(x1 + y1) % (1LL << a) == 0) || (abs(x1 - y1) % (1LL << b) == 0);
    bool bad2 = (abs(x2 + y2) % (1LL << a) == 0) || (abs(x2 - y2) % (1LL << b) == 0);
    
    if(!bad1 && !bad2){
        cout << 0;
        return 0;
    }
    
    long long res = 2;
    if((abs(x1 + y1) % (1LL << a) == 0) == (abs(x2 + y2) % (1LL << a) == 0)){
        res = min(res, 1LL);
    }
    if((abs(x1 - y1) % (1LL << b) == 0) == (abs(x2 - y2) % (1LL << b) == 0)){
        res = min(res, 1LL);
    }
    
    cout << res;
}