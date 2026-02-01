#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> constraints(M);
    for(int i=0; i<M; ++i){
        cin >> constraints[i].first >> constraints[i].second;
    }
    int min_val = -1;

    if(N == 1){
        min_val = (M == 0) ? 0 : -1;
        for(auto c : constraints){
            if(c.first == 1){
                if(min_val == -1 || min_val > c.second){
                    min_val = c.second;
                }
            }else{
                min_val = -1;
            }
        }
    }else if(N == 2){
        min_val = (M == 0) ? 10 : -1;
        for(int i=0; i<=9; ++i){
            for(int j=0; j<=9; ++j){
                if(i == 0 && j == 0) continue;
                bool valid = true;
                for(auto c : constraints){
                    if((c.first == 1 && c.second != i) || (c.first == 2 && c.second != j)){
                        valid = false;
                        break;
                    }
                }
                if(valid){
                    min_val = min(min_val, i*10 + j);
                }
            }
        }
    }else if(N == 3){
        min_val = (M == 0) ? 100 : -1;
        for(int i=0; i<=9; ++i){
            for(int j=0; j<=9; ++j){
                for(int k=0; k<=9; ++k){
                    if(i == 0 && (j > 0 || k > 0)) continue;
                    bool valid = true;
                    for(auto c : constraints){
                        if((c.first == 1 && c.second != i) || (c.first == 2 && c.second != j) || (c.first == 3 && c.second != k)){
                            valid = false;
                            break;
                        }
                    }
                    if(valid){
                        min_val = min(min_val, i*100 + j*10 + k);
                    }
                }
            }
        }
    }
    cout << min_val;
}