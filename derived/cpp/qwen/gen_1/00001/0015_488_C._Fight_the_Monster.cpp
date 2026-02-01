#include <bits/stdc++.h>
using namespace std;

int main(){
    int HPY, ATKY, DEFY;
    int HPM, ATKM, DEFM;
    int h, a, d;
    cin >> HPY >> ATKY >> DEFY;
    cin >> HPM >> ATKM >> DEFM;
    cin >> h >> a >> d;
    
    int min_cost = INT_MAX;
    for(int buy_hp = 0; buy_hp <= 100; ++buy_hp){
        for(int buy_atk = 0; buy_atk <= 100; ++buy_atk){
            for(int buy_def = 0; buy_def <= 100; ++buy_def){
                int new_HPY = HPY + buy_hp;
                int new_ATKY = ATKY + buy_atk;
                int new_DEFY = DEFY + buy_def;
                int cost = buy_hp * h + buy_atk * a + buy_def * d;
                
                int time_to_kill_monster = (ATKY - DEFM) > 0 ? (HPM + (ATKY - DEFM) - 1) / (ATKY - DEFM) : INT_MAX;
                int time_to_kill_yang = (ATKM - new_DEFY) > 0 ? (new_HPY + (ATKM - new_DEFY) - 1) / (ATKM - new_DEFY) : INT_MAX;
                
                if(time_to_kill_monster <= time_to_kill_yang - 1){
                    min_cost = min(min_cost, cost);
                }
            }
        }
    }
    cout << min_cost;
    return 0;
}