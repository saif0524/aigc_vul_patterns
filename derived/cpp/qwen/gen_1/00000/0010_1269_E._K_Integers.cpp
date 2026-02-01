#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> p(n);
    for(auto &x: p) cin >> x;
    vector<long long> f(n + 1);
    for(int k = 1; k <= n; ++k){
        deque<int> dq;
        long long current = 0;
        for(int i = 0; i < k; ++i){
            while(!dq.empty() && p[i] < p[dq.back()]){
                current += i - dq.back();
                dq.pop_back();
            }
            dq.push_back(i);
        }
        f[k] = current;
        for(int i = k; i < n; ++i){
            if(dq.front() <= i - k){
                current -= dq.front() - (i - k);
                dq.pop_front();
            }
            while(!dq.empty() && p[i] < p[dq.back()]){
                current += i - dq.back();
                dq.pop_back();
            }
            dq.push_back(i);
            if(dq.front() == i - k + 1){
                current -= p[dq.front()] - p[i];
            }else{
                current += (i - (i - k + 1)) - (p[dq.front()] - p[i]);
            }
            f[k] = min(f[k], current);
        }
    }
    for(int k = 1; k <= n; ++k){
        cout << f[k] << " ";
    }
    return 0;
}