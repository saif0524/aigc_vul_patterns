#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for(auto &x: a) cin >> x;
    int total_xor = 0;
    for(auto x: a) total_xor ^= x;
    if(total_xor == 0) cout << "Yes";
    else cout << "No";
}