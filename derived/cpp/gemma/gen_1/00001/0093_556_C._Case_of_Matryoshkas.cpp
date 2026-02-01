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

    long long disassemble_time = 0;
    for (int i = 0; i < k; ++i) {
        if (chains[i].size() > 1) {
            disassemble_time += chains[i].size() - 1;
        }
    }

    long long assemble_time = n - 1;

    cout << disassemble_time + assemble_time << endl;

    return 0;
}