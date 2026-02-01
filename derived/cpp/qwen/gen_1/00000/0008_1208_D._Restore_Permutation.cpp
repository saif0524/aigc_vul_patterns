#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> s(n);
    for(auto &x: s) cin >> x;
    set<int> available;
    for(int i=1;i<=n;i++) available.insert(i);
    vector<int> p(n);
    for(int i=0;i<n;i++){
        long long need = s[i];
        long long sum = 0;
        for(auto it = available.begin(); it != available.end(); it++){
            sum += *it;
            if(sum > need){
                p[i] = *it;
                available.erase(it);
                break;
            }
        }
    }
    for(auto &x: p) cout << x << " ";
    cout << "\n";
}