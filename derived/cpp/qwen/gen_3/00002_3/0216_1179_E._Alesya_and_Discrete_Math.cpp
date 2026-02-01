#include <bits/stdc++.h>
using namespace std;

long long query(int func, long long pos) {
    cout << "? " << func << " " << pos << endl;
    fflush(stdout);
    long long res;
    cin >> res;
    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n, L;
    cin >> n >> L;
    long long step = L/n;
    vector<pair<long long, long long>> segments(n);
    for(int i = 0; i < n; i++){
        long long left = 0, right = 1e18;
        while(right - left > 1){
            long long mid = (left + right)/2;
            if(query(i+1, mid) >= step){
                right = mid;
            }
            else{
                left = mid;
            }
        }
        segments[i] = {left, right};
    }
    cout << "!" << endl;
    for(auto &p : segments){
        cout << p.first << " " << p.second << endl;
    }
}