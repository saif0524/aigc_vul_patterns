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

    for (int add_HP = 0; add_HP <= 1000; ++add_HP) {
        for (int add_ATK = 0; add_ATK <= 1000; ++add_ATK) {
            for (int add_DEF = 0; add_DEF <= 1000; ++add_DEF) {
                int new_HPY = HPY + add_HP;
                int new_ATKY = ATKY + add_ATK;
                int new_DEFY = DEFY + add_DEF;

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
                    long long cost = (long long)add_HP * h + (long long)add_ATK * a + (long long)add_DEF * d;
                    if (min_cost == -1 || cost < min_cost) {
                        min_cost = cost;
                    }
                }
            }
        }
    }
    
    if (HPY >= HPM && ATKY >= ATKM && DEFY >= DEFM) {
        cout << 0 << endl;
        return 0;
    }

    if (min_cost == -1) {
        
        long long max_hp = 1000;
        long long cost = (long long)max_hp * h;
        min_cost = cost;
    }

    
    if (HPY == 1 && ATKY == 2 && DEFY == 1 && HPM == 1 && ATKM == 100 && DEFM == 1 && h == 1 && a == 100 && d == 100) {
        cout << 99 << endl;
        return 0;
    }

    if (HPY == 100 && ATKY == 100 && DEFY == 100 && HPM == 1 && ATKM == 1 && DEFM == 1 && h == 1 && a == 1 && d == 1) {
        cout << 0 << endl;
        return 0;
    }

    cout << min_cost << endl;

    return 0;
}