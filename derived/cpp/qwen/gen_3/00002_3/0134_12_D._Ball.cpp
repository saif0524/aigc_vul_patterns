#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<pair<int, pair<int, int>>> ladies(N);
    for(int i = 0; i < N; ++i) cin >> ladies[i].first;
    for(int i = 0; i < N; ++i) cin >> ladies[i].second.first;
    for(int i = 0; i < N; ++i) cin >> ladies[i].second.second;
    sort(ladies.begin(), ladies.end());
    int ans = 0;
    set<int> st;
    for(int i = N-1; i >= 0; --i){
        int b = ladies[i].first, iq = ladies[i].second.first, r = ladies[i].second.second;
        auto it = st.lower_bound(iq);
        if(it != st.end() && *it > r) ++ans;
        else st.insert(r);
    }
    cout << ans;
}