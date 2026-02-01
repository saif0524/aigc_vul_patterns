#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, Y0, Y1;
    cin >> N >> M >> Y0 >> Y1;
    vector<int> mice(N);
    vector<int> cheese(M);
    
    for(auto &m: mice) cin >> m;
    for(auto &c: cheese) cin >> c;

    int hungry = N, i = 0, j = 0;
    while(i < N && j < M){
        if(abs(mice[i] - cheese[j]) < abs(mice[i] - cheese[min(j+1, M-1)])){
            hungry--;
            i++;
            j++;
        }
        else{
            i++;
        }
    }
    cout << hungry;
}