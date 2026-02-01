#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int HPY, ATKY, DEFY;
    int HPM, ATKM, DEFM;
    int h, a, d;
    cin >> HPY >> ATKY >> DEFY >> HPM >> ATKM >> DEFM >> h >> a >> d;

    int min_cost = 1e9;

    for (int extra_hp = 0; extra_hp <= 100; ++extra_hp) {
        for (int extra_atk = 0; extra_atk <= 100; ++extra_atk) {
            for (int extra_def = 0; extra_def <= 100; ++extra_def) {
                int yang_hp = HPY + extra_hp;
                int yang_atk = ATKY + extra_atk;
                int yang_def = DEFY + extra_def;

                int monster_turns = (HPM + max(0, yang_atk - DEFM) - 1) / max(1, yang_atk - DEFM);
                int yang_turns = (yang_hp + max(0, ATKM - yang_def) - 1) / max(1, ATKM - yang_def);

                if (monster_turns < yang_turns) {
                    min_cost = min(min_cost, extra_hp * h + extra_atk * a + extra_def * d);
                }
            }
        }
    }

    cout << min_cost << endl;
    return 0;
}