#include <bits/stdc++.h>
using namespace std;

int main() {
    int vp, vd, t, f, c;
    cin >> vp >> vd >> t >> f >> c;
    
    int princess_distance = vp * t;
    int dragon_distance = 0;
    int bijous = 0;
    
    while (princess_distance < c) {
        int time_to_catch = (princess_distance * (vd - vp)) / (vd * vp);
        int new_dragon_distance = dragon_distance + time_to_catch * vd;
        
        if (new_dragon_distance >= princess_distance) {
            bijous++;
            dragon_distance = 0;
            princess_distance += vp * (t + f);
        } else {
            princess_distance += vp * time_to_catch;
            dragon_distance = new_dragon_distance;
        }
    }
    
    cout << bijous;
}