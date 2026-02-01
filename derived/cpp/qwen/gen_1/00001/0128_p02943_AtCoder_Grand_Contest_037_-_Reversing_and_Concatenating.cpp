#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    string S;
    cin >> N >> K >> S;
    string T = S;
    reverse(T.begin(), T.end());
    string U = S + T;
    string result = S;
    for(int i=0; i<N; i++){
        string candidate = U.substr(i, N);
        if(candidate < result){
            result = candidate;
        }
    }
    if(K % 2 == 0){
        string rev_result = result;
        reverse(rev_result.begin(), rev_result.end());
        U = result + rev_result;
        result = U.substr(0, N);
        for(int i=1; i<N; i++){
            string candidate = U.substr(i, N);
            if(candidate < result){
                result = candidate;
            }
        }
    }
    cout << result;
}