#include <bits/stdc++.h>
using namespace std;

int rev(int x) {
    int ans = 0;
    while (x > 0) {
        ans = ans * 10 + x % 10;
        x /= 10;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int maxx, maxy, w;
    cin >> maxx >> maxy >> w;
    int cnt = 0;
    int ansx = -1, ansy = -1;
    for(int x = 1; x <= maxx; x++){
        for(int y = 1; y <= maxy; y++){
            if(1LL * x * y > 1e9) continue;
            if(x * y == rev(x) * rev(y)){
                cnt++;
            }
            if(cnt >= w){
                ansx = x;
                ansy = y;
                break;
            }
        }
        if(cnt >= w) break;
    }
    if(ansx == -1) cout << "-1\n";
    else cout << ansx << " " << ansy << "\n";
}