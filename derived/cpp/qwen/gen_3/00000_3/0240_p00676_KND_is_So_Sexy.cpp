#include <bits/stdc++.h>
using namespace std;

double calcArea(double a, double l, double x) {
    double s = (a + l + l + x) / 2.0;
    double areaABC = sqrt(s * (s - a) * (s - l) * (s - l));

    double s1 = (a + l + (l + x) / 2.0) / 2.0;
    double areaADC = sqrt(s1 * (s1 - a) * (s1 - l) * (s1 - (l + x) / 2.0));

    double s2 = (a + (l + x) / 2.0 + l) / 2.0;
    double areaBEC = sqrt(s2 * (s2 - a) * (s2 - (l + x) / 2.0) * (s2 - l));

    return areaABC + areaADC + areaBEC;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, l, x;
    while(cin >> a >> l >> x){
        double maxArea = 0.0;
        for(double i = 0.0; i <= x; i += 0.0001){
            double area = calcArea(a, l, i) + calcArea(a, l, x - i);
            maxArea = max(maxArea, area);
        }
        cout << fixed << setprecision(10) << maxArea << "\n";
    }
}