#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    vector<vector<int>> distances = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 12, 23, 40, 48, 52},
        {0, 12, 0, 11, 28, 36, 40},
        {0, 23, 11, 0, 17, 25, 29},
        {0, 40, 28, 17, 0, 8, 12},
        {0, 48, 36, 25, 8, 0, 4},
        {0, 52, 40, 29, 12, 4, 0}
    };
    
    vector<vector<int>> fares = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 450, 850, 1120, 1270, 1430},
        {0, 450, 0, 420, 730, 880, 1040},
        {0, 850, 420, 0, 395, 545, 705},
        {0, 1120, 730, 395, 0, 295, 455},
        {0, 1270, 880, 545, 295, 0, 235},
        {0, 1430, 1040, 705, 455, 235, 0}
    };
    
    while (true) {
        int d, hd, md, a, ha, ma;
        cin >> d;
        if (d == 0) break;
        cin >> hd >> md >> a >> ha >> ma;
        int distance = distances[d][a];
        int fare = fares[d][a];
        bool halfPrice = false;
        if ((hd >= 17 && hd <= 19) || (hd == 17 && md == 30) || (hd == 19 && md == 30)) {
            if (ha >= 17 && ha <= 19 && (md <= 30 || (hd == 17 && md <= 30)) && (ma <= 30 || (hd == 19 && ma <= 30))) {
                halfPrice = true;
            }
        }
        if (halfPrice && distance <= 40) {
            fare /= 2;
        }
        fare = (fare + 49) / 50 * 50; // Round up to the nearest 50 yen
        cout << fare << endl;
    }
    return 0;
}