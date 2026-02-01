#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;
    vector<long long> a(n, 0), diff(n+1, 0);
    vector<pair<int, pair<int,int>>> ops(m);
    for(auto &op : ops){
        cin >> op.first >> op.second.first >> op.second.second;
        if(op.first==1){
            int d;
            cin >> d;
            diff[op.second.first-1] += d;
            diff[op.second.second] -= d;
        }
        else{
            long long maxval;
            cin >> maxval;
            op.second.first = -abs(maxval);
        }
    }
    for(int i=1; i<n; i++){
        diff[i] += diff[i-1];
    }
    for(int i=0; i<n; i++){
        a[i] = diff[i];
    }
    for(auto &op : ops){
        if(op.first==2){
            long long maxval = *max_element(a.begin()+op.second.first-1, a.begin()+op.second.second);
            if(maxval != -op.second.first){
                cout << "NO";
                return 0;
            }
        }
    }
    cout << "YES\n";
    for(auto &x : a){
        cout << x << " ";
    }
}