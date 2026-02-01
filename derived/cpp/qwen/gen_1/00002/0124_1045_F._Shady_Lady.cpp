#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<pair<long long, long long>> terms(N);
    for(auto &t : terms){
        cin >> t.first >> t.second;
    }
    sort(terms.begin(), terms.end());
    int cnt=1;
    for(int i=1;i<N;i++){
        if(terms[i]!=terms[i-1]){
            cnt++;
        }
    }
    if(cnt==N){
        cout << "Ani";
    }
    else{
        cout << "Borna";
    }
}