#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        for(auto &x: a) cin >> x;
        bool found = false;
        for(int k=2;k<n;k++){
            if(a[k] >= a[k-1] + a[k-2]){
                cout << k-1 << " " << k << " " << k+1 << "\n";
                found = true;
                break;
            }
        }
        if(!found){
            cout << "-1\n";
        }
    }
}