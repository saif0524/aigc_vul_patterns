#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int t, m;
    cin >> t >> m;

    vector<pair<int, int>> memory;
    int id = 0;

    for (int i = 0; i < t; i++) {
        string operation;
        cin >> operation;

        if (operation == "alloc") {
            int n;
            cin >> n;

            bool found = false;
            for (int j = 0; j <= m - n; j++) {
                bool free = true;
                for (const auto& block : memory) {
                    if (j < block.first + block.second && j + n > block.first) {
                        free = false;
                        break;
                    }
                }
                if (free) {
                    id++;
                    memory.push_back({j, n});
                    cout << id << endl;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "NULL" << endl;
            }
        } else if (operation == "erase") {
            int x;
            cin >> x;

            bool found = false;
            for (auto it = memory.begin(); it != memory.end(); ++it) {
                if (it->first == -1) continue;
                if (it->second == x) {
                    it->first = -1;
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        } else if (operation == "defragment") {
            vector<pair<int, int>> newMemory;
            int offset = 0;
            for (const auto& block : memory) {
                if (block.first != -1) {
                    newMemory.push_back({offset, block.second});
                    offset += block.second;
                }
            }
            memory = newMemory;
        }
    }

    return 0;
}