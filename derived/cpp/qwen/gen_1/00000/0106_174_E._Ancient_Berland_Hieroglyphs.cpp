#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int la, lb;
    cin >> la >> lb;
    vector<int> a(la), b(lb);
    for(auto &x: a) cin >> x;
    for(auto &x: b) cin >> x;
    vector<int> an(a.begin(), a.end());
    vector<int> bn(b.begin(), b.end());
    for(int i = 0; i < la-1; ++i){
        an.push_back(a[i]);
    }
    for(int i = 0; i < lb-1; ++i){
        bn.push_back(b[i]);
    }
    int res = 0;
    for(int i = 0; i < la; ++i){
        vector<int> ind(lb+1, -1);
        for(int j = 0; j < lb; ++j){
            ind[bn[j]] = j;
        }
        int mx = 0;
        for(int j = 0; j < la; ++j){
            if(ind[an[j+i]] != -1){
                mx = max(mx, ind[an[j+i]]+1);
            }
            else{
                break;
            }
        }
        res = max(res, mx);
    }
    cout << res;
}