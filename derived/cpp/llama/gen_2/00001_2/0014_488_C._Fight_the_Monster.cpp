#include <iostream>
#include <climits>

int main() {
    int hpY, atkY, defY;
    int hpM, atkM, defM;
    int h, a, d;

    std::cin >> hpY >> atkY >> defY;
    std::cin >> hpM >> atkM >> defM;
    std::cin >> h >> a >> d;

    int result = INT_MAX;

    for (int i = 0; i <= 10000; i++) {
        for (int j = 0; j <= 100; j++) {
            for (int k = 0; k <= 100; k++) {
                int newHpY = hpY + i;
                int newAtkY = atkY + j;
                int newDefY = defY + k;

                int timeToKillMonster = (hpM + newAtkY - defM - 1) / (newAtkY - defM);
                if (newAtkY <= defM) {
                    timeToKillMonster = INT_MAX;
                }

                int timeToKillYang = (newHpY + atkM - newDefY - 1) / (atkM - newDefY);
                if (atkM <= newDefY) {
                    timeToKillYang = INT_MAX;
                }

                if (timeToKillMonster != INT_MAX && timeToKillMonster <= timeToKillYang) {
                    result = std::min(result, i * h + j * a + k * d);
                }
            }
        }
    }

    std::cout << result << std::endl;

    return 0;
}