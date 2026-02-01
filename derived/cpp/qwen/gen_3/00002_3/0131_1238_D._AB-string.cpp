#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> l(n, 0), r(n, 0);
    for(int i=0; i<n; i++){
        int j = i, k = i;
        while(j>0 && k<n-1 && s[j-1] == s[k+1]){
            j--, k++;
        }
        l[i] = j, r[i] = k;
    }
    for(int i=n-1; i>=0; i--){
        int j = i, k = i;
        if(i>0 && s[i-1] == s[i]){
            j--, k++;
            while(j>0 && k<n-1 && s[j-1] == s[k+1]){
                j--, k++;
            }
        }
        l[i] = max(l[i], j), r[i] = max(r[i], k);
    }
    long long ans = 0;
    for(int i=0; i<n; i++){
        ans += r[i] - l[i] + 1 - (i-l[i]+1);
    }
    cout << ans;
}