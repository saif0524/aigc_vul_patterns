#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>

using namespace std;

int main() {
    int m;
    while (cin >> m && m != 0) {
        vector<pair<int, int>> constellation(m);
        for (int i = 0; i < m; ++i) {
            cin >> constellation[i].first >> constellation[i].second;
        }
        
        int n;
        cin >> n;
        vector<pair<int, int>> photo(n);
        for (int i = 0; i < n; ++i) {
            cin >> photo[i].first >> photo[i].second;
        }
        
        unordered_map<long long, int> translationCount;
        
        for (const auto& cstar : constellation) {
            for (const auto& pstar : photo) {
                long long dx = pstar.first - cstar.first;
                long long dy = pstar.second - cstar.second;
                long long key = (dx << 32) | dy;
                translationCount[key]++;
            }
        }
        
        long long maxCount = 0;
        long long bestKey = 0;
        for (const auto& entry : translationCount) {
            if (entry.second > maxCount) {
                maxCount = entry.second;
                bestKey = entry.first;
            }
        }
        
        int dx = bestKey >> 32;
        int dy = bestKey & 0xFFFFFFFF;
        cout << dx << " " << dy << endl;
    }
    
    return 0;
}