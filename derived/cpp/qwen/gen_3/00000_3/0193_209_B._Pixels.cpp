#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c;
    cin >> a >> b >> c;
    vector<long long> v = {a, b, c};
    sort(v.begin(), v.end());
    if(v[2] >= v[0] + v[1]){
        if(v[0] + v[1] == 0) cout << 0;
        else cout << v[0] + v[1];
    }
    else cout << v[2] + (v[0] + v[1] - v[2]) / 2;
}