#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    long long d;
    cin >> n >> k >> d;
    vector<long long> a(n);
    for(auto &x : a) cin >> x;
    sort(a.begin(), a.end());
    int i = 0;
    while(i < n){
        int j = i;
        while(j < n && a[j] - a[i] <= d) j++;
        if(j - i >= k){
            i = j;
        }else{
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
}