#include <iostream>
using namespace std;

int main() {
    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    
    int time_passed = t;
    int distance_covered = vp * time_passed;
    int bijous = 0;
    
    while (distance_covered < c) {
        double time_to_meet = (double)(distance_covered) / (vd - vp);
        int new_distance = vp * time_to_meet;
        if (distance_covered + new_distance >= c) break;
        
        bijous++;
        time_passed += time_to_meet + 2 * (time_to_meet + t) + f;
        distance_covered += new_distance;
    }
    
    cout << bijous;
    return 0;
}