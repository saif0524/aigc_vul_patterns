#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> trees(n);
    for(auto &t : trees){
        cin >> t.first >> t.second;
    }
    long long last_cut = -1;
    int count = 0;
    for(int i=0;i<n;i++){
        if(trees[i].first - trees[i].second > last_cut){
            last_cut = trees[i].first;
            count++;
        }
        else if(trees[i].first + trees[i].second > last_cut){
            last_cut = trees[i].first + trees[i].second;
            count++;
        }
    }
    cout << count;
}