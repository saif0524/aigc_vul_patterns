#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    string S;
    cin >> S;
    int count = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'x'){
            if(i+1 < N && S[i+1] == 'x'){
                break;
            }
        }
        count++;
    }
    cout << count << endl;
}