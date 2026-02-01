#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    unordered_set<long long> point_set;
    for(int i = 0; i < n; ++i){
        cin >> points[i].first >> points[i].second;
        point_set.insert(((long long)points[i].first << 32) | points[i].second);
    }
    long long count = 0;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(i != j && points[i].first < points[j].first && points[i].second < points[j].second){
                long long x1 = points[i].first, y1 = points[i].second;
                long long x2 = points[j].first, y2 = points[j].second;
                if(point_set.find(((long long)x1 << 32) | y2) != point_set.end() && 
                   point_set.find(((long long)x2 << 32) | y1) != point_set.end()){
                    count++;
                }
            }
        }
    }
    cout << count;
}