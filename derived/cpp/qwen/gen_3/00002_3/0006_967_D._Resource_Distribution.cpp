#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    long long x1, x2;
    cin >> n >> x1 >> x2;
    vector<long long> c(n);
    for(auto &x: c) cin >> x;
    sort(c.rbegin(), c.rend());
    auto possible = [&](int k1, int k2){
        if(k1 + k2 > n) return false;
        long long need1 = x1 * k1;
        long long need2 = x2 * k2;
        for(int i=0; i<k1; i++){
            if(c[i] < x1 * 1.0 / k1) return false;
            need1 -= c[i];
        }
        for(int i=k1; i<k1+k2; i++){
            if(c[i] < x2 * 1.0 / k2) return false;
            need2 -= c[i];
        }
        return need1 <= 0 && need2 <= 0;
    };
    int k1 = 0, k2 = 0;
    bool found = false;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            if(possible(i, j)){
                k1 = i;
                k2 = j;
                found = true;
                break;
            }
        }
        if(found) break;
    }
    if(!found){
        cout << "No";
        return 0;
    }
    cout << "Yes\n";
    cout << k1 << " " << k2 << "\n";
    vector<int> a, b;
    int idx = 0;
    for(; a.size() < k1; idx++){
        if(c[idx] >= x1 * 1.0 / k1) a.push_back(idx + 1);
    }
    for(; b.size() < k2; idx++){
        if(c[idx] >= x2 * 1.0 / k2) b.push_back(idx + 1);
    }
    for(auto x: a) cout << x << " ";
    cout << "\n";
    for(auto x: b) cout << x << " ";
}