#include <bits/stdc++.h>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> a(n);
    for(auto &i: a) cin >> i;
    sort(a.begin(), a.end(), greater<long long>());
    long long total = 0, rounds = 0;
    for(long long i = 0; i < n; ++i){
        if(a[i] > total){
            rounds += (a[i] - total);
            total = a[i];
        }
        total++;
    }
    cout << rounds;
}