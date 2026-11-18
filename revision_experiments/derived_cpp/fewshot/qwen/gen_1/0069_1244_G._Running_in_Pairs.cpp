#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> p, q;
    int sum = 0;
    for(int i = n; i >= 1; --i){
        if(sum + i > k) break;
        sum += i;
        p.push_back(i);
        q.push_back(1);
    }
    if(p.size() < n){
        for(int i = 1; i <= n; ++i){
            if(sum + i > k) break;
            sum += i;
            p.push_back(1);
            q.push_back(i);
        }
    }
    if(p.size() < n){
        cout << -1 << "\n";
        return 0;
    }
    for(int i = 1; i <= n; ++i){
        if(find(p.begin(), p.end(), i) == p.end()){
            p.push_back(i);
        }
        if(find(q.begin(), q.end(), i) == q.end()){
            q.push_back(i);
        }
    }
    cout << sum << "\n";
    for(auto &x : p) cout << x << " ";
    cout << "\n";
    for(auto &x : q) cout << x << " ";
    cout << "\n";
}