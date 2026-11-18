// [esbmc] replaced #include <bits/stdc++.h> with ESBMC-compatible headers
#include <cassert>
#include <cctype>
#include <cfloat>
#include <climits>
#include <cmath>
#include <cstdint>
#include <cinttypes>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <istream>
#include <ostream>
#include <ios>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <streambuf>
#include <string>
#include <string_view>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
#include <utility>
#include <iterator>
#include <memory>
#include <tuple>
#include <limits>
#include <random>
#include <complex>
#include <valarray>
#include <stdexcept>
#include <exception>
#include <typeinfo>
#include <type_traits>
#include <initializer_list>
#include <numbers>
#include <any>
using namespace std;

typedef complex<double> P;
#define X real()
#define Y imag()
#define EPS (1e-8)

bool in_circle(P p, P c, double r) {
    return abs(p - c) < r - EPS;
}

double dist(P p1, P p2) {
    return abs(p1 - p2);
}

bool valid(P p1, P p2, P c1, double r1, P c2, double r2) {
    if (in_circle(p1, c1, r1) || in_circle(p2, c1, r1) || in_circle(p1, c2, r2) || in_circle(p2, c2, r2))
        return false;
    return true;
}

int main(){
    int n;
    cin >> n;
    P c1, c2;
    double r1, r2;
    cin >> c1.X >> c1.Y >> r1 >> c2.X >> c2.Y >> r2;
    vector<P> red(n), blue(n);
    for(auto &p : red) cin >> p.X >> p.Y;
    for(auto &p : blue) cin >> p.X >> p.Y;
    
    double ans = 1e18;
    vector<int> perm(n);
    iota(perm.begin(), perm.end(), 0);
    do{
        double curr = 0;
        for(int i=0;i<n;i++){
            bool found = false;
            for(double rad=0;rad<=2*acos(-1);rad+=0.01){
                for(double dist=0;dist<=2000;dist+=1){
                    P mid(dist*cos(rad) + c1.X, dist*sin(rad) + c1.Y);
                    if(valid(red[i], blue[perm[i]], c1, r1, c2, r2)){
                        curr += dist(red[i], mid) + dist(blue[perm[i]], mid);
                        found = true;
                        break;
                    }
                }
                if(found) break;
            }
            if(!found){
                cout << "Impossible" << endl;
                return 0;
            }
        }
        ans = min(ans, curr);
    }while(next_permutation(perm.begin(), perm.end()));
    cout << fixed << setprecision(12) << ans << endl;
}