#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, x1, y1, x2, y2;
    cin >> a >> b >> x1 >> y1 >> x2 >> y2;
    int res = 0;
    if((abs(x1 + y1) % (1LL << a) == 0 || abs(x1 - y1) % (1LL << b) == 0) && (abs(x2 + y2) % (1LL << a) == 0 || abs(x2 - y2) % (1LL << b) == 0))
        res = 1;
    if(abs(x1 - x2) % 2 == 0 && abs(y1 - y2) % 2 == 0){
        if(res == 1){
            if(abs(x1 - x2) % (1LL << a) == 0 || abs(y1 - y2) % (1LL << a) == 0 || abs(x1 + y1 - x2 - y2) % (1LL << b) == 0 || abs(x1 - y1 - x2 + y2) % (1LL << b) == 0)
                res = 2;
        }
    }
    else{
        if(res == 1)
            res = 2;
    }
    cout << res;
}