#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, x;
    cin >> q >> x;
    map<int, int> cnt;
    int mex = 0;
    for(int i=0;i<q;i++){
        int y;
        cin >> y;
        int rem = y % x;
        cnt[rem]++;
        while(cnt[mex%x] > mex / x){
            mex++;
        }
        cout << mex << "\n";
    }
}