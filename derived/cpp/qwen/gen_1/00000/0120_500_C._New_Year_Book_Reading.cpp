#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> w(n);
    for(auto &x : w) cin >> x;
    vector<int> b(m);
    for(auto &x : b) cin >> x;

    long long ans = LLONG_MAX;
    do {
        long long total = 0;
        vector<int> pos(n+1);
        for(int i = 0; i < n; ++i) pos[w[i]] = i;
        for(int day = 0, top = 0; day < m; ++day){
            int book = b[day];
            for(int i = top; i < pos[book]; ++i){
                total += w[i];
            }
            top = pos[book]+1;
            for(int i = pos[book]; i > top; --i){
                swap(w[i], w[i-1]);
                pos[w[i]]++;
                pos[w[i-1]]--;
            }
        }
        ans = min(ans, total);
    } while(next_permutation(w.begin(), w.end()));

    cout << ans;
}