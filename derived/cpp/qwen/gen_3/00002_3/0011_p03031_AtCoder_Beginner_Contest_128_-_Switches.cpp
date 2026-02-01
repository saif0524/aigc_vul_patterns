#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<vector<int>> connections(M);
    for(int i=0;i<M;i++){
        int k;
        cin >> k;
        for(int j=0;j<k;j++){
            int s;
            cin >> s;
            connections[i].push_back(s-1);
        }
    }
    vector<int> p(M);
    for(int i=0;i<M;i++){
        cin >> p[i];
    }
    int count = 0;
    for(int mask=0;mask<(1<<N);mask++){
        bool valid = true;
        for(int i=0;i<M;i++){
            int sum = 0;
            for(int j:connections[i]){
                if(mask & (1<<j)){
                    sum++;
                }
            }
            if(sum % 2 != p[i]){
                valid = false;
                break;
            }
        }
        if(valid){
            count++;
        }
    }
    cout << count;
}