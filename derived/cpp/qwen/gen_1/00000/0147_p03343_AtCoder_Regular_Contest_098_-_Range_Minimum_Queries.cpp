#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K, Q;
    cin >> N >> K >> Q;
    vector<int> A(N);
    for(auto &a : A) cin >> a;
    multiset<int> ms;
    for(int i=0;i<K;i++) ms.insert(A[i]);
    vector<int> candidates;
    candidates.push_back(*ms.begin());
    for(int i=K;i<N;i++){
        ms.insert(A[i]);
        ms.erase(ms.find(A[i-K]));
        candidates.push_back(*ms.begin());
    }
    sort(candidates.begin(), candidates.end());
    int ans = INT_MAX;
    for(int i=0;i<=Q-1;i++){
        ans = min(ans, candidates[i+K-1-Q+1] - candidates[i]);
    }
    cout << ans;
}