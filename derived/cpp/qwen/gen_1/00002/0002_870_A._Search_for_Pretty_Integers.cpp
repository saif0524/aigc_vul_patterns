#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    set<int> a, b;
    for(int i=0; i<n; ++i){
        int x;
        cin >> x;
        a.insert(x);
    }
    for(int i=0; i<m; ++i){
        int x;
        cin >> x;
        b.insert(x);
    }
    if(!a.empty() && !b.empty()){
        int min_a = *min_element(a.begin(), a.end());
        int min_b = *min_element(b.begin(), b.end());
        int ans = min(min_a, min_b) * 10 + max(min_a, min_b);
        if(a.find(min_b) != a.end() || b.find(min_a) != b.end()){
            ans = min(ans, min(min_a, min_b));
        }
        cout << ans;
    }
}