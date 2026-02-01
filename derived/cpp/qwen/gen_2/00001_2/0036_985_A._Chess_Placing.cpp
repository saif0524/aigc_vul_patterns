#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int k = n / 2;
    vector<int> pieces(k);
    for(auto &p : pieces) cin >> p;
    sort(pieces.begin(), pieces.end());
    
    int cost_black = 0, cost_white = 0;
    for(int i=0; i<k; i++){
        cost_black += abs(pieces[i] - (2 * i + 1));
        cost_white += abs(pieces[i] - (2 * i + 2));
    }
    
    cout << min(cost_black, cost_white) << endl;
}