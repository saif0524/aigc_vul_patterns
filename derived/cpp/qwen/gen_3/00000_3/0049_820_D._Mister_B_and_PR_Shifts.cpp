#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int &x : p) cin >> x;
    vector<ll> sum(n+1,0);
    for(int i=0;i<n;i++){
        sum[i+1] = sum[i] + abs(p[i] - (i+1));
    }
    ll min_deviation = sum[n];
    int shift_id = 0;
    for(int k=1;k<n;k++){
        ll current_deviation = sum[n] - 2*sum[k] + k - n + abs(p[k-1] - k) - abs(p[k-1] - n);
        if(current_deviation < min_deviation){
            min_deviation = current_deviation;
            shift_id = k;
        }
    }
    cout << min_deviation << " " << shift_id;
}