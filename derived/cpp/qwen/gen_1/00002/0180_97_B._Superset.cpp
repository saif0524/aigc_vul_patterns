#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    set<pair<long long, long long>> points;
    vector<long long> x;
    vector<long long> y;
    for(int i=0;i<n;i++){
        long long xi, yi;
        cin >> xi >> yi;
        points.insert({xi, yi});
        x.push_back(xi);
        y.push_back(yi);
    }
    set<long long> xs(begin(x), end(x));
    set<long long> ys(begin(y), end(y));
    for(auto xi : xs){
        for(auto yi : ys){
            points.insert({xi, yi});
        }
    }
    cout << points.size() << "\n";
    for(auto p : points){
        cout << p.first << " " << p.second << "\n";
    }
}