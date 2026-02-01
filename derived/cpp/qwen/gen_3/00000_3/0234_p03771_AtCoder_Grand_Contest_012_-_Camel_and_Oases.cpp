#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, V;
    cin >> N >> V;
    vector<long long> x(N);
    for(int i=0; i<N; i++) cin >> x[i];
    
    auto can_visit_all = [&](int start){
        int current_v = V;
        long long current_x = x[start];
        for(int i=start; i<N; i++){
            if(x[i] <= current_x) continue;
            long long needed_water = x[i] - current_x;
            if(needed_water > current_v){
                if(current_v == 0) return false;
                int jumps = 0;
                while(needed_water > current_v){
                    jumps++;
                    current_v /= 2;
                    if(current_v == 0) return false;
                }
                current_v -= needed_water;
                for(int j=0; j<jumps-1; j++){
                    current_v /= 2;
                    if(current_v == 0) return false;
                }
            }else{
                current_v -= needed_water;
            }
            current_x = x[i];
        }
        return true;
    };
    
    for(int i=0; i<N; i++){
        if(can_visit_all(i)){
            cout << "Possible\n";
        }else{
            cout << "Impossible\n";
        }
    }
}