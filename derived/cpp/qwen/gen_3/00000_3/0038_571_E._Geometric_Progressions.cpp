#include <bits/stdc++.h>
using namespace std;

const int MOD = 1000000007;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    for(int i=0;i<n;i++){
        cin >> a[i] >> b[i];
    }
    if(n==1){
        cout << a[0] % MOD;
        return 0;
    }
    set<long long> s;
    s.insert(a[0]);
    for(int i=1;i<n;i++){
        set<long long> ns;
        long long current = a[i];
        while(current <= *s.begin()){
            ns.insert(current);
            current *= b[i];
        }
        set_intersection(s.begin(), s.end(), ns.begin(), ns.end(), inserter(s, s.begin()));
        if(s.empty()){
            cout << -1;
            return 0;
        }
    }
    cout << *s.begin() % MOD;
}