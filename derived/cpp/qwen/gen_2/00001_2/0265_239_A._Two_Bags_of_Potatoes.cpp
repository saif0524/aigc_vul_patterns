#include <bits/stdc++.h>
using namespace std;

int main(){
    long long y, k, n;
    cin >> y >> k >> n;
    vector<long long> ans;
    for(long long s = y + k; s <= n; s += k){
        long long x = s - y;
        if(x >= 1){
            ans.push_back(x);
        }
    }
    if(ans.empty()){
        cout << "-1";
    }
    else{
        for(size_t i = 0; i < ans.size(); ++i){
            if(i > 0) cout << " ";
            cout << ans[i];
        }
    }
}