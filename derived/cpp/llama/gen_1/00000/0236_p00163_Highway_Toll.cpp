#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int d, hd, md, a, ha, ma;
    while (true) {
        cin >> d;
        if (d == 0) break;
        cin >> hd >> md;
        cin >> a;
        cin >> ha >> ma;

        int dis[] = {0, 0, 3, 6, 12, 23, 35, 58};
        int cost[] = {0, 0, 100, 200, 450, 850, 1300, 2000};

        int dist = abs(dis[d] - dis[a]);
        int price = cost[max(d, a)] - cost[min(d, a)];

        bool isHalf = false;
        if ((hd >= 17 && hd < 19) || (hd == 19 && md <= 30)) isHalf = true;
        if ((ha >= 17 && ha < 19) || (ha == 19 && ma <= 30)) isHalf = true;

        if (isHalf && dist <= 40) {
            price = (int)ceil((double)price / 2 / 50) * 50;
        } else {
            price = (int)ceil((double)price / 50) * 50;
        }

        cout << price << endl;
    }
    return 0;
}