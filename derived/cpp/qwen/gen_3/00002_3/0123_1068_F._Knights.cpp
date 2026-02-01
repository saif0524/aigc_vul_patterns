#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<pair<long long, long long>> knights;
    
    for(int i = 0; i < n; ++i) {
        long long x = (i / 3) * 4 + (i % 3) % 2;
        long long y = (i / 3) * 4 + (i % 3) / 2;
        knights.push_back({x, y});
    }
    
    for(auto [x, y] : knights) {
        cout << x << " " << y << "\n";
    }
    
    return 0;
}