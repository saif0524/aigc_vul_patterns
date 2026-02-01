#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, V;
    cin >> N >> V;
    vector<long long> x(N);
    for(auto &i: x) cin >> i;
    vector<string> result(N, "Impossible");
    
    for(int start = 0; start < N; ++start){
        int water = V;
        bool can_visit_all = true;
        long long current_pos = x[start];
        for(int i = 0; i < N; ++i){
            long long target_pos = x[i];
            long long distance = abs(target_pos - current_pos);
            if(water >= distance){
                water -= distance;
                current_pos = target_pos;
            }
            else{
                if(water == 0){
                    can_visit_all = false;
                    break;
                }
                while(water > 0 && water < distance){
                    water = water / 2;
                    if(water == 0){
                        can_visit_all = false;
                        break;
                    }
                }
                if(water >= distance){
                    water -= distance;
                    current_pos = target_pos;
                }
                else{
                    can_visit_all = false;
                    break;
                }
            }
        }
        if(can_visit_all) result[start] = "Possible";
    }
    
    for(const auto &r: result) cout << r << "\n";
    return 0;
}