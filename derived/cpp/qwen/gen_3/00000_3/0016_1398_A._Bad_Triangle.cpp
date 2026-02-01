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
        vector<long long> a(n);
        for(auto &x : a) cin >> x;
        int found = -1;
        for(int i=0;i<n-2;i++){
            if(a[i] + a[i+1] <= a[i+2]){
                found = i;
                break;
            }
        }
        if(found != -1){
            cout << found+1 << " " << found+2 << " " << found+3 << "\n";
        }else{
            cout << "-1\n";
        }
    }
}