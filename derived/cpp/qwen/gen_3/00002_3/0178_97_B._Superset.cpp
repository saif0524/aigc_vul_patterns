#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    set<pair<int, int>> points;
    for(int i=0; i<n; i++){
        int x, y;
        cin >> x >> y;
        points.insert({x, y});
    }
    set<int> x_vals, y_vals;
    for(auto [x, y] : points){
        x_vals.insert(x);
        y_vals.insert(y);
    }
    vector<int> x_list(x_vals.begin(), x_vals.end());
    vector<int> y_list(y_vals.begin(), y_vals.end());
    for(auto [x, y] : points){
        cout << x << " " << y << "\n";
    }
    for(int i=0; i<x_list.size(); i++){
        for(int j=0; j<y_list.size(); j++){
            if(points.find({x_list[i], y_list[j]}) == points.end()){
                cout << x_list[i] << " " << y_list[j] << "\n";
            }
        }
    }
}