#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    if(n==1){
        cout << 1;
        return 0;
    }
    int ans = 1;
    long long last = a[0];
    long long diff = 0;
    int cnt = 1;
    for(int i=1;i<n;i++){
        if(a[i] == -1){
            if(cnt == 1){
                diff = 0;
            }
        }
        else{
            if(cnt == 1){
                if(i+1 < n && a[i+1] != -1){
                    diff = a[i+1] - a[i];
                }
                else{
                    diff = 0;
                }
            }
            else{
                if(last + diff != a[i]){
                    ans++;
                    diff = a[i] - last;
                }
            }
            last = a[i];
        }
        cnt++;
    }
    cout << ans;
}