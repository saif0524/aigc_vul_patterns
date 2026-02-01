#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<long long> A(N);
    for(auto &a : A) cin >> a;
    sort(A.rbegin(), A.rend());
    long long ans = 0;
    for(int i=0; i<N; i++){
        ans += A[i] * (i + 1);
        ans -= A[i] * (N - i - 1);
    }
    cout << ans;
}