#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    vector<ll> A(N);
    ll totalSum = 0;
    for(auto &x : A){
        cin >> x;
        totalSum += x;
    }
    int Q;
    cin >> Q;
    unordered_map<ll, ll> countMap;
    for(const auto &x : A){
        countMap[x]++;
    }
    while(Q--){
        ll B, C;
        cin >> B >> C;
        if(countMap.find(B) != countMap.end()){
            ll countB = countMap[B];
            totalSum -= countB * B;
            totalSum += countB * C;
            countMap[C] += countB;
            countMap.erase(B);
        }
        cout << totalSum << "\n";
    }
}