#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main() {
    int t, m;
    cin >> t >> m;

    vector<pair<int, int>> blocks;
    int blockId = 1;

    for (int i = 0; i < t; ++i) {
        string op;
        cin >> op;

        if (op == "alloc") {
            int size;
            cin >> size;

            bool found = false;
            for (int j = 0; j <= m - size; ++j) {
                bool isFree = true;
                for (const auto& block : blocks) {
                    if (j < block.second && j + size > block.first) {
                        isFree = false;
                        break;
                    }
                }

                if (isFree) {
                    blocks.emplace_back(j, j + size);
                    cout << blockId << endl;
                    blockId++;
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "NULL" << endl;
            }
        }
        else if (op == "erase") {
            int id;
            cin >> id;

            bool found = false;
            for (auto it = blocks.begin(); it != blocks.end(); ++it) {
                if (it->first == id) {
                    blocks.erase(it);
                    found = true;
                    break;
                }
            }

            if (!found) {
                cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
            }
        }
        else if (op == "defragment") {
            vector<pair<int, int>> newBlocks;
            int offset = 0;

            for (const auto& block : blocks) {
                newBlocks.emplace_back(offset, offset + (block.second - block.first));
                offset += block.second - block.first;
            }

            blocks = newBlocks;
        }
    }

    return 0;
}