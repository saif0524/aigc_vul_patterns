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
        for(int i=0;i<n;i++) cin >> a[i];
        sort(a.begin(), a.end());
        long long sum=0, left=0, right=0;
        for(int i=0;i<n;i++) right+=a[i];
        for(int i=1;i<n;i++) left+=a[i-1], right-=a[i-1], sum+=1LL*i*a[i-1]-left-1LL*(n-i)*(right-a[i-1]);
        cout << sum << "\n";
    }
}