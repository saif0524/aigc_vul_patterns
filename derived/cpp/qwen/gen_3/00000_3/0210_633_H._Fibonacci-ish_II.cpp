#include <bits/stdc++.h>
using namespace std;

const int MAX = 30005;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    int q;
    cin >> q;
    vector<pair<int,int>> queries(q);
    for(int i=0;i<q;i++) cin >> queries[i].first >> queries[i].second, queries[i].first--, queries[i].second--;

    vector<long long> fib(MAX+2);
    fib[1] = fib[2] = 1;
    for(int i=3;i<=MAX;i++) fib[i] = (fib[i-1] + fib[i-2]) % m;

    vector<long long> results(q);
    for(int i=0;i<q;i++){
        set<long long> unique_elements;
        for(int j=queries[i].first; j<=queries[i].second; j++) unique_elements.insert(a[j]);
        long long result = 0;
        int index = 1;
        for(auto val: unique_elements) {
            result = (result + (val * fib[index]) % m) % m;
            index++;
        }
        results[i] = result;
    }
    for(auto result: results) cout << result << "\n";
}