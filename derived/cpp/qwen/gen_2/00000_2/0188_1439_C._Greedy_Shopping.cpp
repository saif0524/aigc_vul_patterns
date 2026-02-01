#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    vector<long long> lazy(n, 0);
    for(int i=0; i<q; ++i){
        int t, x;
        long long y;
        cin >> t >> x >> y;
        --x;
        if(t == 1){
            for(int j=x; j<n && lazy[j]<y; ++j){
                lazy[j] = max(lazy[j], y);
                a[j] = max(a[j], lazy[j]);
            }
        }
        else{
            long long money = y;
            int count = 0;
            for(int j=x; j<n && money >= a[j]; ++j){
                money -= a[j];
                count++;
                while(j+1 < n && a[j] == a[j+1] && money >= a[j+1]){
                    ++j;
                    ++count;
                    money -= a[j];
                }
            }
            cout << count << "\n";
        }
    }
}