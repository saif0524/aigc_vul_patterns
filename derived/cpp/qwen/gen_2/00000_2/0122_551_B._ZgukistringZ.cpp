#include <bits/stdc++.h>
using namespace std;

int main(){
    string a, b, c;
    cin >> a >> b >> c;
    int n = a.size(), m1 = b.size(), m2 = c.size();
    vector<int> dp1(n+1, 0), dp2(n+1, 0);
    for(int i=1;i<=n;i++){
        dp1[i] = dp1[i-1];
        dp2[i] = dp2[i-1];
        if(i>=m1){
            if(a.substr(i-m1, m1) == b){
                dp1[i] = max(dp1[i], dp2[i-m1]+1);
            }
        }
        if(i>=m2){
            if(a.substr(i-m2, m2) == c){
                dp2[i] = max(dp2[i], dp1[i-m2]+1);
            }
        }
        dp1[i] = max(dp1[i], dp1[i-1]);
        dp2[i] = max(dp2[i], dp2[i-1]);
    }
    int mx = max(dp1[n], dp2[n]);
    int i = n;
    string k;
    while(mx > 0){
        if(dp1[i] == mx && i-m1 >=0 && a.substr(i-m1, m1) == b){
            k = b + k;
            i -= m1;
            mx--;
        }
        else if(dp2[i] == mx && i-m2 >=0 && a.substr(i-m2, m2) == c){
            k = c + k;
            i -= m2;
            mx--;
        }
        else{
            k = a[i-1] + k;
            i--;
        }
    }
    for(int j=0;j<i;j++){
        k = a[j] + k;
    }
    cout << k;
}