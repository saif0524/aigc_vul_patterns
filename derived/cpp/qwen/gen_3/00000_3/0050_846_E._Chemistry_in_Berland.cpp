#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<ll> b(n);
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin >> b[i];
    for(int i=0;i<n;i++) cin >> a[i];
    vector<pair<int,ll>> transforms(n);
    for(int i=1;i<n;i++){
        int x;
        ll k;
        cin >> x >> k;
        transforms[i] = {x-1, k};
    }
    for(int i=n-1;i>0;i--){
        int x = transforms[i].first;
        ll k = transforms[i].second;
        ll need = a[i];
        ll extra = b[i] - need;
        if(extra >= 0){
            b[x] += extra;
        }
        else{
            ll deficit = -extra;
            if(b[x] >= deficit * k){
                b[x] -= deficit * k;
                b[i] += deficit;
            }
            else{
                cout << "NO";
                return 0;
            }
        }
    }
    if(b[0] >= a[0]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}