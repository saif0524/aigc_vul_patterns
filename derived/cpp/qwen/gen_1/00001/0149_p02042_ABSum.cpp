#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(auto &x: A) cin >> x;
    long long ans = 0;
    multiset<int> small, large;
    for(int i=0; i<N; i++){
        if(A[i] <= i){
            small.insert(A[i]);
        }
        else{
            large.insert(A[i]);
        }
    }
    while(M > 0 && !small.empty() && !large.empty()){
        auto it_s = small.begin();
        auto it_l = --large.end();
        if(*it_l - *it_s > 1){
            int s = *it_s;
            int l = *it_l;
            small.erase(it_s);
            large.erase(it_l);
            small.insert(s+1);
            large.insert(l-1);
            M--;
        }
        else{
            break;
        }
    }
    for(int i=0; i<N; i++){
        if(small.count(A[i])){
            ans += abs(A[i] - i);
            small.erase(small.find(A[i]));
        }
        else{
            ans += abs(A[i] - i);
        }
    }
    cout << ans << "\n";
}