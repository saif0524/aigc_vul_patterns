#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    
    int odd = 0, even = 0;
    for(auto x: a){
        if(x != 0){
            if(x % 2 == 0){
                even++;
            }else{
                odd++;
            }
        }
    }
    
    int ans = min(odd, even);
    cout << ans;
    return 0;
}