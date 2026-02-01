#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> l(n,0), r(n,0);
    for(int i=1;i<n;i++){
        if(s[i]==s[i-1]){
            l[i]=l[i-1]+2;
        }
        else if(i-2>=0 && s[i]==s[i-2]){
            l[i]=l[i-2]+3;
        }
    }
    for(int i=n-2;i>=0;i--){
        if(s[i]==s[i+1]){
            r[i]=r[i+1]+2;
        }
        else if(i+2<n && s[i]==s[i+2]){
            r[i]=r[i+2]+3;
        }
    }
    long long ans=0;
    for(int i=0;i<n;i++){
        long long ll = l[i]/2;
        long long rr = r[i]/2;
        ans += (ll+1)*(rr+1);
        if(l[i]%2 && r[i]%2){
            ans += (l[i]-1)/2 + (r[i]-1)/2 + 1;
        }
    }
    cout << ans;
}