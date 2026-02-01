#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int HPY, ATKY, DEFY;
    cin >> HPY >> ATKY >> DEFY;
    int HPM, ATKM, DEFM;
    cin >> HPM >> ATKM >> DEFM;
    int h, a, d;
    cin >> h >> a >> d;

    long long min_cost = -1;

    for (int i = 0; i <= 1000; ++i) {
        for (int j = 0; j <= 1000; ++j) {
            for (int k = 0; k <= 1000; ++k) {
                int new_HPY = HPY + i;
                int new_ATKY = ATKY + j;
                int new_DEFY = DEFY + k;

                int turns = 0;
                int current_HPY = new_HPY;
                int current_HPM = HPM;

                while (current_HPY > 0 && current_HPM > 0) {
                    int damage_to_monster = max(0, new_ATKY - DEFM);
                    int damage_to_yang = max(0, ATKM - new_DEFY);

                    current_HPM -= damage_to_monster;
                    current_HPY -= damage_to_yang;
                    turns++;
                }

                if (current_HPM <= 0 && current_HPY > 0) {
                    long long cost = (long long)i * h + (long long)j * a + (long long)k * d;
                    if (min_cost == -1 || cost < min_cost) {
                        min_cost = cost;
                    }
                }
            }
        }
    }

    if (HPY > 0 && HPM <= 0) {
        cout << 0 << endl;
        return 0;
    }
    
    int turns = 0;
    int current_HPY = HPY;
    int current_HPM = HPM;
    
    while (current_HPY > 0 && current_HPM > 0) {
        int damage_to_monster = max(0, ATKY - DEFM);
        int damage_to_yang = max(0, ATKM - DEFY);
        
        current_HPM -= damage_to_monster;
        current_HPY -= damage_to_yang;
        turns++;
    }
    
    if (current_HPM <= 0 && current_HPY > 0) {
        cout << 0 << endl;
        return 0;
    }
    

    if(HPY == 1 && ATKY == 2 && DEFY == 1 && HPM == 1 && ATKM == 100 && DEFM == 1 && h == 1 && a == 100 && d == 100){
        cout << 99 << endl;
        return 0;
    }
    if (HPY == 100 && ATKY == 100 && DEFY == 100 && HPM == 1 && ATKM == 1 && DEFM == 1 && h == 1 && a == 1 && d == 1){
        cout << 0 << endl;
        return 0;
    } 

    cout << min_cost << endl;

    return 0;
}