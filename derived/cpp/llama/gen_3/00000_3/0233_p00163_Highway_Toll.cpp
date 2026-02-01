#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int d, hd, md, a, ha, ma;
    int tolls[][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 200, 250, 400, 550, 700},
        {0, 200, 0, 450, 600, 750, 900},
        {0, 250, 450, 0, 300, 500, 650},
        {0, 400, 600, 300, 0, 250, 400},
        {0, 550, 750, 500, 250, 0, 200},
        {0, 700, 900, 650, 400, 200, 0}
    };

    while (true) {
        cin >> d;
        if (d == 0) break;
        cin >> hd >> md >> a >> ha >> ma;

        int baseToll = tolls[d][a];
        int departureTime = hd * 60 + md;
        int arrivalTime = ha * 60 + ma;
        int halfPriceTimeStart = 17 * 60 + 30;
        int halfPriceTimeEnd = 19 * 60 + 30;
        bool isHalfPriceTime = false;

        if (departureTime >= halfPriceTimeStart && departureTime <= halfPriceTimeEnd) {
            isHalfPriceTime = true;
        }
        if (arrivalTime >= halfPriceTimeStart && arrivalTime <= halfPriceTimeEnd) {
            isHalfPriceTime = true;
        }

        int toll;
        if (isHalfPriceTime) {
            toll = ceil(baseToll / 2.0);
        } else {
            toll = baseToll;
        }

        cout << (ceil(toll / 50.0) * 50) << endl;
    }

    return 0;
}