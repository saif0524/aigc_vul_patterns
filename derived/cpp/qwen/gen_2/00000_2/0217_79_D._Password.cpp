#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, l;
    cin >> n >> k >> l;
    vector<int> x(k);
    for(auto &xi : x) cin >> xi;
    vector<int> a(l);
    for(auto &ai : a) cin >> ai;
    
    vector<int> target(n+1, 0);
    for(auto xi : x) target[xi] = 1;
    
    int result = 0;
    for(int i=1; i<=n; ++i){
        if(target[i] == 0) continue;
        bool found = false;
        for(auto ai : a){
            if(i + ai - 1 > n) continue;
            found = true;
            result++;
            for(int j=i; j<=i+ai-1; ++j) target[j] = 1 - target[j];
            break;
        }
        if(!found) {
            cout << -1;
            return 0;
        }
    }
    
    cout << result;
}