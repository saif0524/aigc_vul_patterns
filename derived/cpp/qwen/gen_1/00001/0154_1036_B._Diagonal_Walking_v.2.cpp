#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int64_t maxDiagonalMoves(int64_t nx, int64_t ny, int64_t k) {
    int64_t minSteps = max(nx, ny);
    int64_t maxDiag = min(nx + ny, k);
    if (k < minSteps || (k - minSteps) % 2 != 0) {
        return -1;
    }
    return maxDiag - (k - minSteps) / 2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    vector<pair<pair<int64_t, int64_t>, int64_t>> queries(q);
    for(auto &query : queries){
        cin >> query.first.first >> query.first.second >> query.second;
    }
    for(const auto &query : queries){
        int64_t result = maxDiagonalMoves(query.first.first, query.first.second, query.second);
        cout << result << "\n";
    }
}