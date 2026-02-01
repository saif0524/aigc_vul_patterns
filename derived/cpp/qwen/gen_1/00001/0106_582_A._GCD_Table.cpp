#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> gcd_table(n*n);
    for(int &x: gcd_table) cin >> x;
    sort(gcd_table.begin(), gcd_table.end(), greater<int>());
    vector<int> a(n);
    set<int> used;
    int idx = 0;
    for(int i=0; i<n; ++i){
        while(used.count(gcd_table[idx])) idx++;
        a[i] = gcd_table[idx];
        used.insert(a[i]);
        for(int j=0; j<i; ++j){
            int g = __gcd(a[i], a[j]);
            used.insert(g);
        }
    }
    for(int i=0; i<n; ++i){
        if(i) cout << " ";
        cout << a[i];
    }
    cout << "\n";
}