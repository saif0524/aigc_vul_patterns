#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> a(6,0), b(6,0);
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        a[x]++;
    }
    for(int i=0; i<n; i++){
        int x;
        cin >> x;
        b[x]++;
    }
    int diff=0, ans=0;
    for(int i=1; i<=5; i++){
        int d = a[i]-b[i];
        if(d%2==1){
            cout << -1;
            return 0;
        }
        if(d>0){
            ans+=d/2;
        }
    }
    cout << ans;
}