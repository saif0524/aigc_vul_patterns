#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(auto &x: a) cin >> x;
    
    int mx = *max_element(a.begin(), a.end());
    int cnt = 0;
    for(auto &x: a) if(x == mx) cnt++;
    
    if(mx == 1){
        if(N % 2 == 0) cout << "Second";
        else cout << "First";
    }
    else{
        if(cnt % 2 == 0) cout << "Second";
        else cout << "First";
    }
}