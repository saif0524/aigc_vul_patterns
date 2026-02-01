#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    set<int> s;
    int mex = 0;
    for(int i=0;i<n;i++){
        s.insert(a[i]);
        while(s.count(mex)) mex++;
        if(a[i] > mex) {
            cout << i+1;
            return 0;
        }
    }
    cout << -1;
}