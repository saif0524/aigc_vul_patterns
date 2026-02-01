#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<vector<int>> chains(k);
    for (int i = 0; i < k; ++i) {
        int mi;
        cin >> mi;
        for (int j = 0; j < mi; ++j) {
            int ai;
            cin >> ai;
            chains[i].push_back(ai);
        }
    }

    int disassembly_time = 0;
    for (int i = 0; i < k; ++i) {
        disassembly_time += chains[i].size() - 1;
    }

    int assembly_time = n - 1;

    cout << disassembly_time + assembly_time << endl;

    return 0;
}