#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> a(n);
    for(auto &x: a) cin >> x;
    map<long long, vector<int>> m;
    for(int i=0;i<n;i++) m[a[i]].push_back(i);
    long long sum=LLONG_MIN;
    pair<int,int> range={-1,-1};
    for(const auto &[val, idxs]: m){
        if(idxs.size()>=2){
            for(int i=0,j=idxs.size()-1;i<j;i++,j--){
                long long current_sum = accumulate(a.begin()+idxs[i], a.begin()+idxs[j]+1, 0LL);
                if(current_sum > sum){
                    sum = current_sum;
                    range = {idxs[i], idxs[j]};
                }
                break; // Only need the first and last to satisfy the condition
            }
        }
    }
    cout << sum << " " << (n-(range.second-range.first+1)) << "\n";
    for(int i=0;i<n;i++){
        if(i<range.first || i>range.second){
            cout << i+1 << " ";
        }
    }
    cout << "\n";
}