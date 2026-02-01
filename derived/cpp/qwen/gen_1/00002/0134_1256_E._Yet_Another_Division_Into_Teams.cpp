#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    sort(a.begin(), a.end());
    long long min_diversity = LLONG_MAX;
    int team_size = 0;
    for(int sz=3;sz<=5;sz++){
        long long sum = 0;
        for(int i=sz-1;i<n;i+=sz){
            sum += a[i] - a[i-sz+1];
        }
        if(sum < min_diversity){
            min_diversity = sum;
            team_size = sz;
        }
    }
    vector<int> teams(n);
    int cnt = 1;
    for(int i=0;i<n;i+=team_size){
        for(int j=0;j<team_size && i+j<n;j++){
            teams[i+j] = cnt;
        }
        cnt++;
    }
    cout << min_diversity << " " << cnt-1 << "\n";
    for(auto &x: teams) cout << x << " ";
    cout << "\n";
}