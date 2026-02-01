#include <bits/stdc++.h>
using namespace std;

struct IC {
    int distance;
    int fare;
};

int calculateFare(const vector<IC>& ics, int d, int a, int hd, int md, int ha, int ma) {
    int totalDistance = 0;
    int totalFare = 0;
    
    if (d > a) {
        swap(d, a);
        swap(hd, ha);
        swap(md, ma);
    }
    
    for (int i = d; i < a; ++i) {
        totalDistance += ics[i].distance;
        totalFare += ics[i].fare;
    }
    
    bool isHalfPrice = (hd == 17 && md >= 30) || (hd == 18) || (hd == 19 && md <= 30);
    bool isHalfPriceArrival = (ha == 17 && ma >= 30) || (ha == 18) || (ha == 19 && ma <= 30);
    
    if (isHalfPrice && isHalfPriceArrival && totalDistance <= 40) {
        totalFare /= 2;
    }
    
    totalFare = (totalFare + 49) / 50 * 50;
    return totalFare;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    vector<IC> ics(7);
    ics[1] = {12, 450};
    ics[2] = {14, 520};
    ics[3] = {14, 520};
    ics[4] = {14, 520};
    ics[5] = {7, 260};
    ics[6] = {7, 260};
    
    while(true){
        int d, a, hd, md, ha, ma;
        cin >> d;
        if(d == 0) break;
        cin >> hd >> md >> a >> ha >> ma;
        cout << calculateFare(ics, d, a, hd, md, ha, ma) << endl;
    }
    
    return 0;
}