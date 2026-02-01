#include <bits/stdc++.h>
using namespace std;

double calculate_area(double a, double l, double x) {
    double s = (a + 2 * l + x) / 2;
    double M = sqrt(s * (s - a) * (s - (l + x / 2)) * (s - (l + x / 2)));
    return M;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    double a, l, x;
    while(cin >> a >> l >> x){
        double M = calculate_area(a, l, x);
        cout << fixed << setprecision(10) << M << endl;
    }
    return 0;
}