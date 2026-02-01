#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> points;
    for(int i=0;i<n;i++){
        int x, y, r;
        cin >> x >> y >> r;
        points.push_back({x, y});
    }
    sort(points.begin(), points.end());
    int mid = points[n/2].first;
    int midy = points[n/2].second;
    cout << "t" << endl;
    cout << "abs((t-" << midy << "))";
}