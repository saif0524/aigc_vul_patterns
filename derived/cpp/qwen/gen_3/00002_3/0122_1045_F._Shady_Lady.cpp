#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<long long, long long>> terms(n);
    for(auto &t : terms){
        cin >> t.first >> t.second;
    }
    sort(terms.begin(), terms.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b){
        return a.first + a.second < b.first + b.second;
    });
    if(terms[0].first + terms[0].second == 0){
        cout << "Borna";
    }
    else{
        cout << "Ani";
    }
}