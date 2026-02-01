#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int k = n/2;
    vector<int> ps(k);
    for(auto &p: ps) cin >> p;
    sort(ps.begin(), ps.end());
    int costB = 0, costW = 0;
    for(int i=0; i<k; ++i){
        costB += abs(ps[i] - (2*i + 1));
        costW += abs(ps[i] - (2*i + 2));
    }
    cout << min(costB, costW);
}