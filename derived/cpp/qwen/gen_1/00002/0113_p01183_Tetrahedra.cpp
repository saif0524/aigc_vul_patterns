#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAX = 16;
const int COMB = 1 << MAX;
const double EPS = 1e-6;

bool checkTriangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

bool checkTetrahedron(int a, int b, int c, int d, int e, int f) {
    return checkTriangle(a, b, c) && checkTriangle(a, d, e) && checkTriangle(b, d, f) && checkTriangle(c, e, f);
}

double volumeTetrahedron(int a, int b, int c, int d, int e, int f) {
    double s1 = sqrt((a + b + c) * (a + b - c) * (a - b + c) * (-a + b + c)) / 4.0;
    double s2 = sqrt((d + e + f) * (d + e - f) * (d - e + f) * (-d + e + f)) / 4.0;
    double g1 = (0.5 * a * b * sin(acos((a * a + b * b - c * c) / (2.0 * a * b))));
    double g2 = (0.5 * a * d * sin(acos((a * a + d * d - e * e) / (2.0 * a * d))));
    double g3 = (0.5 * b * d * sin(acos((b * b + d * d - f * f) / (2.0 * b * d))));
    double g4 = (0.5 * c * e * sin(acos((c * c + e * e - f * f) / (2.0 * c * e))));
    return (g1 * s2 * sin(acos((g1 * g1 + s2 * s2 - g2 * g2 - g3 * g3 - g4 * g4) / (2 * g1 * s2)))) / 3.0;
}

int main(){
    while(true){
        int n;
        cin >> n;
        if(n == 0) break;
        vector<int> sticks(n);
        for(int &stick : sticks) cin >> stick;
        double maxVolume = 0;
        for(int mask = 1; mask < (1 << n); mask++){
            if(__builtin_popcount(mask) != 6) continue;
            vector<int> edges;
            for(int i = 0; i < n; i++){
                if(mask & (1 << i)){
                    edges.push_back(sticks[i]);
                }
            }
            sort(edges.begin(), edges.end());
            do{
                if(checkTetrahedron(edges[0], edges[1], edges[2], edges[3], edges[4], edges[5])){
                    double vol = volumeTetrahedron(edges[0], edges[1], edges[2], edges[3], edges[4], edges[5]);
                    if(vol > maxVolume){
                        maxVolume = vol;
                    }
                }
            }while(next_permutation(edges.begin(), edges.end()));
        }
        cout << fixed;
        cout.precision(10);
        cout << maxVolume << endl;
    }
    return 0;
}