#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        long long n;
        cin >> n;
        vector<long long> r(n), c(n);
        for(long long i=0;i<n;i++) cin >> r[i];
        for(long long i=0;i<n;i++) cin >> c[i];
        vector<long long> points;
        for(long long i=0;i<n;i++) points.push_back((r[i]-1)*r[i]/2 + c[i]);
        sort(points.begin(), points.end());
        long long current = 1;
        long long cost = 0;
        for(long long p : points){
            while(current != p){
                if((current%(long long(sqrt(2*current)) + 1))%2 == 0){
                    current++;
                }
                else{
                    current += 1 + (long long(sqrt(8*current - 7)))/2;
                }
                cost++;
            }
            current = p;
        }
        cout << cost << "\n";
    }
}