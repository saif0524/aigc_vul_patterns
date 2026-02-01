#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    long long x;
    cin >> N >> x;
    vector<long long> a(N);
    for(auto &ai: a) cin >> ai;
    sort(a.begin(), a.end());
    int ans = 0;
    for(int i=0; i<N; i++){
        if(x >= a[i]){
            x -= a[i];
            ans++;
        }
        else break;
    }
    cout << ans;
}