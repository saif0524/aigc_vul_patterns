#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    long long ans = 0;
    stack<int> s;
    for(int i = 0; i < n; ++i){
        int cur = 0;
        while(!s.empty() && (cur | a[s.top()]) < a[i]){
            cur |= a[s.top()];
            ans += i - s.top();
            s.pop();
        }
        s.push(i);
    }
    cout << ans;
}