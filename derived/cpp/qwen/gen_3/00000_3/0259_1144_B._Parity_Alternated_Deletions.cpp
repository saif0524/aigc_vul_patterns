#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    long long sum = 0;
    priority_queue<int> even, odd;
    for(auto x: a){
        sum += x;
        if(x % 2) odd.push(x);
        else even.push(x);
    }
    while(!even.empty() && !odd.empty()){
        sum -= even.top();
        even.pop();
        if(even.empty()) break;
        sum -= even.top();
        even.pop();
        if(odd.empty()) break;
        sum -= odd.top();
        odd.pop();
        if(odd.empty()) break;
        sum -= odd.top();
        odd.pop();
    }
    cout << sum;
}