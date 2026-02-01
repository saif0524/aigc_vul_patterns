#include <bits/stdc++.h>
using namespace std;

string to_string(long long n) {
    if (n == 0) return "0";
    string s;
    while (n > 0) {
        s += char('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long N, M;
    cin >> N >> M;
    vector<long long> a(N);
    for(auto &x : a) cin >> x;
    vector<long long> b(M);
    for(auto &x : b) cin >> x;
    long long Q;
    cin >> Q;
    vector<long long> d(Q);
    for(auto &x : d) cin >> x;
    vector<vector<string>> grid(N, vector<string>(M));
    vector<long long> prefix_sum(N * M + 1, 0);
    for(long long i = 0; i < N; ++i){
        for(long long j = 0; j < M; ++j){
            grid[i][j] = to_string(a[i] * b[j]);
            prefix_sum[i * M + j + 1] = prefix_sum[i * M + j] + grid[i][j].size();
        }
    }
    string ans;
    for(auto &x : d){
        if(x > prefix_sum.back()){
            ans += 'x';
            continue;
        }
        long long row = lower_bound(prefix_sum.begin(), prefix_sum.end(), x) - prefix_sum.begin();
        long long col = row % M;
        row /= M;
        long long offset = x - prefix_sum[row * M + col];
        ans += grid[row][col][offset - 1];
    }
    cout << ans;
}