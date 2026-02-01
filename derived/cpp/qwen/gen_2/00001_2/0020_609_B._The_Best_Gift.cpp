#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> genre_count(m+1, 0);
    for(int i = 0; i < n; ++i){
        int genre;
        cin >> genre;
        ++genre_count[genre];
    }
    long long total_ways = 0;
    for(int i = 1; i <= m; ++i){
        for(int j = i + 1; j <= m; ++j){
            total_ways += 1LL * genre_count[i] * genre_count[j];
        }
    }
    cout << total_ways;
}