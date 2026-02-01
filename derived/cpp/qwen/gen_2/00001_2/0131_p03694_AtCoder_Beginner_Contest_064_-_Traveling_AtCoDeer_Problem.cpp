#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    int ans = INT_MAX;
    for(int i=0; i<N-1; ++i){
        ans = min(ans, a[i+1]-a[i]);
    }
    cout << ans;
}