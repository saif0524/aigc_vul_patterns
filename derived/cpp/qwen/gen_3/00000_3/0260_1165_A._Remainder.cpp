#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x, y;
    cin >> n >> x >> y;
    string s;
    cin >> s;
    int ans = n-x;
    for(int i=x-1;i>=y;i--) if(s[i]!='0') ans++;
    for(int i=y-1;i>=0;i--) if(s[i]!='1') ans++;
    cout << ans;
}