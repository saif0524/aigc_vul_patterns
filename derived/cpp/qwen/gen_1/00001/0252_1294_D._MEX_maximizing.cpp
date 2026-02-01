#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q, x;
    cin >> q >> x;
    vector<long long> a;
    vector<long long> count(x, 0);
    long long mex = 0;
    for(int i = 0; i < q; ++i){
        long long y;
        cin >> y;
        a.push_back(y);
        count[y % x]++;
        while(count[mex % x] > mex / x){
            mex++;
        }
        cout << mex << "\n";
    }
}