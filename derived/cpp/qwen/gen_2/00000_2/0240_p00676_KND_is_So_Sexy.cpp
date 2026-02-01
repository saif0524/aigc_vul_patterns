#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double calculateMaxArea(int a, int l, int x) {
    double maxArea = 0.0;
    double step = 0.00001;
    for (double angle = 0.0; angle <= 180.0; angle += step) {
        double radians = angle * M_PI / 180.0;
        double halfBase = a / 2.0;
        double height = halfBase * tan(radians);
        double originalArea = halfBase * height;
        
        double remainingSlack = x;
        double newHeightD = height + remainingSlack * sin(radians);
        double newHeightE = height + remainingSlack * sin(radians);
        double areaD = halfBase * newHeightD;
        double areaE = halfBase * newHeightE;
        
        double totalArea = originalArea + areaD + areaE;
        if (totalArea > maxArea) {
            maxArea = totalArea;
        }
    }
    return maxArea;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int a, l, x;
    while (cin >> a >> l >> x) {
        double result = calculateMaxArea(a, l, x);
        cout << fixed << setprecision(10) << result << endl;
    }
    return 0;
}