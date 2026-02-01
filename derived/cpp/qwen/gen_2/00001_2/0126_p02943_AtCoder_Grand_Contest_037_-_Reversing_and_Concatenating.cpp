#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, K;
    string S;
    cin >> N >> K >> S;
    string T = S;
    reverse(T.begin(), T.end());
    string U = S + T;
    string res = S;
    for(int i=0;i<N;i++){
        string sub = U.substr(i, N);
        res = min(res, sub);
    }
    if(K % 2 == 1){
        cout << res << "\n";
    }
    else{
        string rev_res = res;
        reverse(rev_res.begin(), rev_res.end());
        res = min(res, rev_res);
        cout << res << "\n";
    }
}