#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(auto &x : a) cin >> x;
    for(auto &x : b) cin >> x;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int result = INT_MAX;
    for(int ai : a){
        for(int bi : b){
            result = min(result, min(ai*10+bi, bi*10+ai));
        }
    }
    if(a[0] != b[0]){
        result = min(result, min(a[0], b[0]));
    }
    cout << result;
}