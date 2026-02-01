#include <bits/stdc++.h>
using namespace std;

struct Domino {
    long long x, h;
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Domino> dominoes(n);
    for(auto &d: dominoes){
        cin >> d.x >> d.h;
    }
    vector<int> ans(n, 1);
    map<long long, int> m;
    for(int i = 0; i < n; ++i){
        auto it = m.upper_bound(dominoes[i].x);
        if(it != m.begin()){
            --it;
            if(it->first + it->second - 1 >= dominoes[i].x){
                ans[it->second-1] += ans[i];
                ans[i] = 0;
            }
        }
        if(ans[i]){
            m[dominoes[i].x + dominoes[i].h - 1] = i + 1;
        }
    }
    for(int i = 0; i < n; ++i){
        if(i) cout << " ";
        cout << ans[i];
    }
}