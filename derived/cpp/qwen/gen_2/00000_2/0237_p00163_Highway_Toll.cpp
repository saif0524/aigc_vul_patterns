#include <bits/stdc++.h>
using namespace std;

bool isHalfPriceTime(int h, int m) {
    return (h == 17 && m >= 30) || (h == 18) || (h == 19 && m <= 30);
}

int main(){
    while(true){
        int d, hd, md, a, ha, ma;
        cin >> d;
        if(d == 0) break;
        cin >> hd >> md;
        cin >> a >> ha >> ma;
        int dist[8][8] = {
            {0},
            {0, 0, 7, 13, 25, 50, 58},
            {0, 7, 0, 6, 18, 43, 51},
            {0, 13, 6, 0, 12, 37, 45},
            {0, 25, 18, 12, 0, 25, 33},
            {0, 50, 43, 37, 25, 0, 8},
            {0, 58, 51, 45, 33, 8, 0}
        };
        int fare[8][8] = {
            {0},
            {0, 0, 350, 520, 820, 1740, 1950},
            {0, 350, 0, 310, 610, 1530, 1740},
            {0, 520, 310, 0, 430, 1350, 1560},
            {0, 820, 610, 430, 0, 670, 880},
            {0, 1740, 1530, 1350, 670, 0, 370},
            {0, 1950, 1740, 1560, 880, 370, 0}
        };
        int distance = dist[d][a];
        int toll = fare[d][a];
        if(distance <= 40 && ((isHalfPriceTime(hd, md) && d == 1) || (isHalfPriceTime(ha, ma) && a == 7))){
            toll = (toll / 2 + 49) / 50 * 50;
        }
        cout << toll << endl;
    }
}