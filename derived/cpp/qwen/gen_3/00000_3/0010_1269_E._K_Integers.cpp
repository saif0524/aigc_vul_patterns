#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &x: p) cin >> x;
    vector<long long> f(n+1, 0);
    deque<int> dq;
    long long cost = 0;
    for(int i=0; i<n; ++i){
        dq.push_back(p[i]);
        cost += abs(p[i] - (i+1));
        if(dq.size() > i+1){
            cost -= abs(dq.front() - 1);
            dq.pop_front();
        }
        if(dq.size() == i+1){
            f[i+1] = cost;
            for(int j=0; j<i+1; ++j){
                if(dq[j] == j+1) continue;
                cost -= abs(dq[j] - (j+1));
                cost += abs(dq[j] - (i+2-j));
                swap(dq[j], dq[i+1-j-1]);
            }
        }
    }
    for(int i=1; i<=n; ++i){
        if(i>1) cout << " ";
        cout << f[i];
    }
    cout << "\n";
}