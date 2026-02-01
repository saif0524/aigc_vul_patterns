#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int A, B, C;
    cin >> A >> B >> C;
    
    if(A == 0){
        if(B == 0){
            if(C == 0){
                cout << -1;
            } else {
                cout << 0;
            }
        } else {
            cout << 1 << endl;
            cout << fixed << setprecision(10) << -static_cast<double>(C) / B;
        }
    } else {
        long long discriminant = static_cast<long long>(B) * B - 4LL * A * C;
        if(discriminant < 0){
            cout << 0;
        } else if(discriminant == 0){
            cout << 1 << endl;
            cout << fixed << setprecision(10) << -static_cast<double>(B) / (2 * A);
        } else {
            double root1 = (-B + sqrt(discriminant)) / (2.0 * A);
            double root2 = (-B - sqrt(discriminant)) / (2.0 * A);
            vector<double> roots = {root1, root2};
            sort(roots.begin(), roots.end());
            cout << 2 << endl;
            for(double root : roots){
                cout << fixed << setprecision(10) << root << endl;
            }
        }
    }
}