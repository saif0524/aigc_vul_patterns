#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> constraints(M);
    for (int i = 0; i < M; ++i) {
        cin >> constraints[i].first >> constraints[i].second;
    }
    
    int smallest = -1;
    int start = (N == 1) ? 0 : 1;
    int end = (N == 1) ? 9 : pow(10, N) - 1;
    
    for (int num = start; num <= end; ++num) {
        string numStr = to_string(num);
        bool valid = true;
        for (const auto& [s, c] : constraints) {
            if (numStr[s - 1] - '0' != c) {
                valid = false;
                break;
            }
        }
        if (valid) {
            smallest = num;
            break;
        }
    }
    
    cout << smallest << endl;
    return 0;
}